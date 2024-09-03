// #include<bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <cassert>
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

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
//const ll MOD=1000000007;
const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T,typename U>T & chmax(T &a,const U &b){if(a<b){a=b;} return a;}
template<typename T,typename U>T & chmin(T &a,const U &b){if(b<a){a=b;} return a;}


template<long long int mod=1000000007>
struct Mod_Int{
    typedef long long int ll;
    typedef pair<ll,ll> pll;
    typedef Mod_Int<mod> M;
    ll a;
    
    ll mod_pow(ll a,ll x){
        a%=mod;
        ll ans=1;
        for(int i=0;i<63;i++){
            if(x>>i&1){ans*=a; ans%=mod;}
            a*=a;
            a%=mod;
        }
        return ans;
    }
    
    pll Ex_gcd(ll a,ll b){
        if(b==0){return {1,0};}
        pll ret=Ex_gcd(b,a%b);
        ret.F-=a/b*ret.S;
        return {ret.S,ret.F};
    }
    
    ll prime_R(ll a){
        return mod_pow(a,mod-2);
    }
    
    ll R(ll a){
        ll ret=Ex_gcd(a,mod).F;
        ret%=mod;
        if(ret<0){ret+=mod;}
        return ret;
    }
    
    Mod_Int(ll A=1):a(A){
        a%=mod;
        if(a<0){a+=mod;}
    }
    
    Mod_Int(const M &b):a(b.a){}
    
    M & operator += (const M &b){
        a+=b.a;
        if(a>=mod){a-=mod;}
        return *this;
    }
    
    M operator + (const M &b) const {
        M c=*this;
        return c+=b;
    }
    
    M & operator -= (const M &b){
        a-=b.a;
        if(a<0){a+=mod;}
        return *this;
    }
    
    M operator - (const M &b) const {
        M c=*this;
        return c-=b;
    }
    
    M & operator *= (const M &b){
        (a*=b.a)%=mod;
        return *this;
    }
    
    M operator * (const M &b) const {
        M c=*this;
        return c*=b;
    }
    
    M & operator /= (const M &b){
        (a*=R(b.a))%=mod;
        return *this;
    }
    
    M operator / (const M &b) const {
        M c=*this;
        return c/=b;
    }
    
    M & mod_pow_equal(ll x){
        ll ans=1;
        while(x>0){
            if(x&1){ans*=a; ans%=mod;}
            a*=a;
            a%=mod;
            x>>=1;
        }
        a=ans;
        return *this;
    }
    
    M mod_pow(ll x){
        M c(a);
        return c.mod_pow_equal(x);
    }
    
    bool operator == (const M &b) const {return a==b.a;}
    
    bool operator != (const M &b) const {return a!=b.a;}
    
    bool operator <= (const M &b) const {return a<=b.a;}
    
    bool operator < (const M &b) const {return a<b.a;}
    
    bool operator > (const M &b) const {return a>b.a;}
    
    bool operator >= (const M &b) const {return a>=b.a;}
    
    M & operator = (const M &b){
        a=b.a;
        return *this;
    }
    
    M & operator = (const ll &b){
        (a=b)%=mod;
        if(a<0){a+=mod;}
        return *this;
    }
};

template<long long MOD>istream & operator >> (istream &i,Mod_Int<MOD> &A){ll a; cin>>a; A=Mod_Int<MOD>(a); return i;}
template<long long MOD>ostream & operator << (ostream &i,const Mod_Int<MOD> &A){i<<A.a; return i;}

using Int=Mod_Int<MOD>;

const int MAX=2100;

int N,K;
int P[MAX];
int A[MAX]={};
Int dp[MAX][MAX];
Int tmp[MAX];

void init(){
  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      dp[i][j]=0;
    }
    dp[i][A[i]]=1;
  }
}

void merge(int p,int u){
  for(int i=0;i<MAX;i++){tmp[i]=0;}
  dp[u][0]+=1;
  for(int i=0;i<MAX;i++){
    for(int j=0;i+j<MAX;j++){
      tmp[i+j]+=dp[p][i]*dp[u][j];
    }
  }
  for(int i=0;i<MAX;i++){dp[p][i]=tmp[i];}
}

void solve(){
  cin>>N>>K;
  assert(K!=1);
  for(int i=0;i<N;i++){cin>>A[i];}
  for(int i=1;i<N;i++){cin>>P[i]; P[i]--;}
  init();
  for(int i=N-1;i>0;i--){merge(P[i],i);}
  cout<<dp[0][K]<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  solve();

  return 0;
}
