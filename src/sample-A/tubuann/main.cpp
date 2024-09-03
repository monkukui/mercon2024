//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<random>
#include<string>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<cassert>
#include<fstream>
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
  string S,T;
  cin>>S;
  for(int i=0;i<N;i++){
    if(i==0 || S[i]!=S[i-1]){T.push_back(S[i]);}
  }
  if(!T.empty() && T.back()=='A'){T.pop_back();}
  reverse(T.begin(),T.end());
  if(!T.empty() && T.back()=='A'){T.pop_back();}
  cout<<T.size()/2<<endl;
  
  return 0;
}
