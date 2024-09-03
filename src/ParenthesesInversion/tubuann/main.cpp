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


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  if(N%2!=0){cout<<-1<<endl; return 0;}
  string S;
  cin>>S;
  vector<ll> A(N);
  cin>>A;
  for(auto &I:S){
    if(I=='('){I=1;}
    else{I=-1;}
  }
  int idx=0;
  {
    int mi=0,sum=0;
    for(int i=0;i<N;i++){
      sum+=S[i];
      if(sum<mi){mi=sum; idx=i+1;}
    }
  }
  ll ans=0;
  auto cul=
    [&](int M){
      priority_queue<ll,vector<ll>,greater<ll>> Q;
      int s=0,mi=0;
      for(int i=0;i<M;i++){mi+=S[i];}
      for(int i=0;i<M;i++){
        s+=S[i];
        if(S[i]==-1){Q.push(A[i]);}
        if(s<0){s+=2; ans+=Q.top(); Q.pop();}
      }
    };
  cul(idx);
  idx=N-idx;
  reverse(A.begin(),A.end());
  reverse(S.begin(),S.end());
  for(auto &I:S){I*=-1;}
  cul(idx);
  cout<<ans<<endl;
  

  return 0;
}
