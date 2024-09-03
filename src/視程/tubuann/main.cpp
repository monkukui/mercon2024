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
const ll MOD=1000000007;
//const ll MOD=998244353;

template<typename T,typename U>istream & operator >> (istream &i,pair<T,U> &A){i>>A.F>>A.S; return i;}
template<typename T>istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;}
template<typename T,typename U>ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.F<<" "<<A.S; return o;}
template<typename T>ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?" ":"");} return o;}
template<typename T,typename U>T & chmax(T &a,const U &b){if(a<b){a=b;} return a;}
template<typename T,typename U>T & chmin(T &a,const U &b){if(b<a){a=b;} return a;}

//kasanattetaramienai
bool totu(pll a,pll b,pll c){
  return (b.S-a.S)*(c.F-b.F)<=(c.S-b.S)*(b.F-a.F);
}

void solve(){
  ll N;
  cin>>N;
  vector<pll> A;
  for(int x=0;x<N;x++){
    ll y;
    cin>>y;
    assert(y<=MOD);
    pll p={x,y};
    while(A.size()>=2 && totu(A[A.size()-2],A[A.size()-1],p)){A.pop_back();}
    A.push_back(p);
  }
  ll mx=0,ls=0;
  for(auto &I:A){chmax(mx,I.F-ls); ls=I.F;}
  cout<<mx<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}
