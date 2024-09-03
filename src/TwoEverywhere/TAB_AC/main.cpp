#include <array>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#include <iostream>
#include <cassert>

template<long long mod>
class modint{
private:
  using T = long long;
  T a;
public:
  constexpr modint(const long long x = 0) noexcept : a((x%mod+mod)%mod) {}
  constexpr T& value() noexcept { return a; }
  constexpr const T& value() const noexcept { return a; }
  constexpr modint operator-() const noexcept {
    return modint(0) -= *this;
  }
  constexpr modint operator+(const modint& rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint& rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint& rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint& rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint& operator+=(const modint& rhs) noexcept {
    a += rhs.a;
    if(a >= mod) a -= mod;
    return *this;
  }
  constexpr modint &operator-=(const modint& rhs) noexcept {
    if(a < rhs.a) a += mod;
    a -= rhs.a;
    return *this;
  }
  constexpr modint& operator*=(const modint& rhs) noexcept {
    a = a*rhs.a%mod;
    return *this;
  }
  constexpr modint& operator/=(const modint& rhs) noexcept {
    return *this *= rhs.inv();
  }
  constexpr bool operator==(const modint& rhs) const noexcept {
    return a == rhs.a;
  }
  constexpr bool operator!=(const modint& rhs) const noexcept {
    return not (*this == rhs);
  }
  constexpr modint pow(long long k) const noexcept {
    modint ret(1);
    modint x = k > 0 ? *this : this->inv();
    k = abs(k);
    while(k > 0){
      if(k&1) ret *= x;
      x *= x;
      k >>= 1;
    }
    return ret;
  }
  constexpr modint inv() const noexcept {
    return pow(mod-2);
  }
  friend std::ostream& operator<<(std::ostream &os, const modint &X) noexcept {
    return os << X.a;
  }
  friend std::istream& operator>>(std::istream &is, modint &X) noexcept {
    is >> X.a;
    X.a %= mod;
    if(X.a < 0) X.a += mod;
    return is;
  }
};

const int mod = 998244353;
using mint = modint<mod>;
// using mint = double;

#include <vector>
#include <cassert>

template<typename T>
struct Combination {
private:
  int sz;
  vector<T> F, F_;
public:
  Combination(int sz) : sz(sz), F(sz+1), F_(sz+1) {
    F[0] = 1;
    for(int i = 0; i < sz; ++i) F[i+1] = F[i]*(i+1);
    F_.back() = (T)1/F.back();
    for(int i = sz-1; i >= 0; --i) F_[i] = F_[i+1]*(i+1);
  }
  T C(int n, int k){
    assert(n <= sz);
    if(n < 0 or k > n) return (T)0;
    return F[n]*F_[k]*F_[n-k];
  }
  T P(int n, int k){
    assert(n <= sz);
    if(n < 0 or k > n) return (T)0;
    return F[n]*F_[n-k];
  }
};

void debug(vector<vector<mint>> mat){
  cerr << string(100,'-') << endl;
  for(const auto& v : mat){
    for(auto e : v)
      cerr << setw(9) << right << e << ' ';
    cerr << endl;
  }
}

int main(){
  int n;
  cin >> n;
  if(n == 2){
    cout << 2 << endl;
    return 0;
  }
  int m = (n+2)*(n+1)/2;
  vector idx(n+1,vector(n+1,0));
  {
    int t = 0;
    for(int i = 0; i <= n; ++i){
      for(int j = 0; j <= n; ++j){
        if(i+j > n) continue;
        idx[i][j] = t++;
      }
    }
    assert(t == m);
  }
  Combination<mint> comb(n);
  vector mat(m,vector(m+1,mint(0)));
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      if(i+j > n) continue;
      mat[idx[i][j]][idx[i][j]] = 1;
      if(i == 0 and j == 0) continue;
      array<int,3> a = {i,j,n-i-j};
      for(int k = 0; k < 3; ++k){
        for(int l = k; l < 3; ++l){
          auto b = a;
          if(b[k] < 1) continue;
          --b[k];
          ++b[(k+1)%3];
          if(b[l] < 1) continue;
          --b[l];
          ++b[(l+1)%3];
          mint x = (k == l ? comb.C(a[k],2) : comb.C(a[k],1)*comb.C(a[l],1))/comb.C(n,2);
          // mint x = (k == l ? mint(a[k])*(a[k]-1)/2 : mint(a[k])*a[l])/(mint(n)*(n-1)/2);
          auto [i_,j_,k_] = b;
          assert(i_+j_+k_ == n);
          mat[idx[i][j]][idx[i_][j_]] -= x;
          mat[idx[i][j]].back() += x;
        }
      }
    }
  }

  // debug(mat);

  for(int i = 0; i < m; ++i){
    if(mat[i][i] == mint(0)){
      for(int j = i+1; j < m; ++j){
        if(mat[j][i] == mint(0)) continue;
        swap(mat[i],mat[j]);
        break;
      }
      if(mat[i][i] == mint(0)){
        cout << 0 << endl;
        return 0;
      }
    }
    mint t = mat[i][i];
    for(int k = 0; k <= m; ++k){
      mat[i][k] /= t;
    }
    for(int j = 0; j < m; ++j){
      if(i == j) continue;
      mint u = mat[j][i];
      for(int k = 0; k <= m; ++k)
        mat[j][k] -= u*mat[i][k];
    }
  }

  // debug(mat);

  cout << mat[idx[n][0]].back() << endl;
}
