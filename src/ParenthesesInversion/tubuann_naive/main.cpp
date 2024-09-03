// #include<bits/stdc++.h>
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
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll,ll> pll;
typedef long double D;
//typedef complex<D> P;
#define F first
#define S second
const ll MOD=1000000007;
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T,typename U>T & chmax(T &a,const U &b){if(a<b){a=b;} return a;}
template<typename T,typename U>T & chmin(T &a,const U &b){if(b<a){a=b;} return a;}

const ll INF=1e15;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  string S;
  cin>>S;
  vector<ll> A(N);
  cin>>A;
  int sz=N+1;
  vector<ll> dp(sz,INF),nx(sz);
  dp[0]=0;
  for(int i=0;i<N;i++){
    ll a=(S[i]=='('?0:A[i]);
    ll b=(S[i]==')'?0:A[i]);
    for(auto &I:nx){I=INF;}
    for(int j=0;j<sz;j++){
      if(j+1<sz){chmin(nx[j+1],dp[j]+a);}
      if(j-1>=0){chmin(nx[j-1],dp[j]+b);}
    }
    swap(dp,nx);
  }
  cout<<dp[0]<<endl;

  return 0;
}
