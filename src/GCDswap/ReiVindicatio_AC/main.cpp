// #include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
#include <cassert>
using namespace std;

const int INF = 1e9;
const long long inf = 1LL<<60;
using ll = long long;

template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const { long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u); }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ostream& operator<<(ostream& st, const ModInt<MOD> a) { st << a.get(); return st; };
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r; }
typedef ModInt<998244353> mint;


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

int main() {
  int n; cin >> n;
  vector<int> b;
  Combination<mint> comb(n+10);
  vector<int> cnt(10);
  for (int i=0; i<n; i++) {
    int a; cin >> a;
    if (a == 1 || a == 5 || a == 7) cnt[a]++;
    else b.emplace_back(a);
  }
  mint ans = mint(1);
  int even = 0, odd = 0;
  for (int i=0; i<b.size(); i++) {
    if (b[i] == 6) {
      ans *= comb.C(even + odd, even);
      even = 0; odd = 0;
      continue;
    }
    if (b[i] & 1) odd++;
    else even++;
  }
  ans *= comb.C(even + odd, even);
  ans *= comb.C(n, cnt[1]);
  ans *= comb.C(n-cnt[1], cnt[5]);
  ans *= comb.C(n-cnt[1]-cnt[5], cnt[7]);
  cout << ans << '\n';
}
