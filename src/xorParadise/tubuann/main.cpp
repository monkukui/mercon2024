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

const int SZ=60;
using vec=bitset<SZ>;
using mat=vector<vec>;

int dot(vec a,vec b){
  return (a&b).count()%2;
}

void gauss(mat &A){
  int sz=A.size();
  int idx=0;
  for(int i=0;i<SZ && idx<sz;i++){
    for(int j=idx+1;j<sz;j++){
      if(A[j][i]){swap(A[j],A[idx]);}
    }
    if(A[idx][i]){
      for(int j=idx+1;j<sz;j++){
        if(A[j][i]){A[j]^=A[idx];}
      }
      idx++;
    }
  }
  while(!A.empty() && A.back()==0){A.pop_back();}
}

mat ortho(mat A){
  int sz=A.size();
  mat ret;
  int idx=0;
  vector<int> tp;
  for(int i=0;i<SZ;i++){
    if(idx==sz || A[idx][i]==false){
      vec v=1LL<<i;
      for(int j=idx-1;j>=0;j--){
        if(dot(v,A[j])){v^=1LL<<tp[j];}
      }
      ret.push_back(v);
    }
    else{tp.push_back(i); idx++;}
  }
  gauss(ret);
  return ret;
}

void solve(){
  ll K;
  cin>>K;
  vector<ll> N(K);
  cin>>N;
  vector<vector<vec>> A(K);
  for(int i=0;i<K;i++){A[i].resize(N[i]);}
  for(auto &I:A){
    for(auto &J:I){ll a; cin>>a; J=vec(a);}
  }
  for(auto &I:A){gauss(I); I=ortho(I);}
  __int128 ans=0;
  for(int msk=1;msk<(1<<K);msk++){
    vector<vec> tmp;
    for(int i=0;i<K;i++){
      if(msk>>i&1){for(auto &I:A[i]){tmp.push_back(I);}}
    }
    gauss(tmp);
    int sgn=(vec(msk).count()&1?1:-1);
    ll sz=SZ-tmp.size();
    ans+=(1LL<<sz)*sgn;
  }
  cout<<(ll)ans<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}
