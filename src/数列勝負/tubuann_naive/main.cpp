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

using vec=vector<pll>;

bool good(vec A){
  for(auto &I:A){if(I.F<I.S){return false;}}
  return true;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin>>N;
  vec A(N);
  for(auto &I:A){cin>>I.F;}
  for(auto &I:A){cin>>I.S;}
  if(good(A)){cout<<0<<endl; return 0;}
  sort(A.begin(),A.end());
  queue<vec> uku;
  map<vec,int> M;
  uku.push(A);
  M[A]=0;
  while(1){
    vec tmp=uku.front(); uku.pop();
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        vec nx=tmp;
        swap(nx[i].F,nx[j].S);
        sort(nx.begin(),nx.end());
        if(M.count(nx)){continue;}
        M[nx]=M[tmp]+1;
        uku.push(nx);
        if(good(nx)){cout<<M[nx]<<endl; return 0;}
      }
    }
  }

  return 0;
}
