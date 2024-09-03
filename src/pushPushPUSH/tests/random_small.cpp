//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<random>
#include<string>
#include<vector>
#include<set>
#include<utility>
#include<cassert>
#include<fstream>
//#include "constraints.hpp"
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

const int CASE=100;
int N;
int M;

const ll seed=3827631762932782765LL;

mt19937_64 R(seed);

//[mi,mx)
ll Int(ll mi,ll mx){
    assert(mx>mi);
    ull w=mx-mi;
    ull k=1;
    while(w>k){k<<=1;}
    ull x=w;
    while(x>=w){x=R()&(k-1);}
    return (ll)x+mi;
}


vector<ll>& Rand_Perm(vector<ll> &ret,ll n){
  ret.resize(n);
    for(int i=0;i<n;i++){
        ret[i]=i+1;
        ll l=Int(0,i+1);
        if(l!=i){swap(ret[l],ret[i]);}
    }
    return ret;
}

template<typename T>
vector<T>& Rand_Shuffle(vector<T> &ret){
  for(int i=1;i<ret.size();i++){
    ll l=Int(0,i+1);
    if(l!=i){swap(ret[l],ret[i]);}
  }
  return ret;
}


vector<vector<ll>> edge(100,vector<ll>(100,0));
int K;
vector<ll> v;
int s,t;

void build(){
  for(auto &I:edge){
    for(auto &J:I){J=0;}
  }
  v.clear();
}

void out(string file){
  ofstream ofs(file,ios::out);
  ofs<<N<<" "<<M<<endl;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(edge[i][j]){ofs<<i+1<<" "<<j+1<<endl;}
    }
  }
  ofs<<K<<endl;
  for(auto &I:v){I++;}
  ofs<<v<<endl;
  ofs<<s+1<<" "<<t+1<<endl;
  ofs.close();
}

void test(){
  static string num="00000";
  string file="10_randsmall_"+num+".in";
  N=Int(2,16);
  M=Int(N-1,N*(N-1)/2+1);
  build();
  K=Int(1,N+1);
  {
    int cnt=0;
    for(int i=1;i<N;i++){
      int j=Int(0,i);
      edge[i][j]=edge[j][i]=1;
      cnt++;
    }
    while(cnt<M){
      int a=Int(0,N),b=Int(0,N);
      if(a!=b && edge[a][b]==0){edge[a][b]=1; edge[b][a]=1; cnt++;}
    }
  }
  if(2*K>N){
    vector<ll> emp(N,0);
    int cnt=0;
    while(cnt+K<N){
      int a=Int(0,N);
      if(emp[a]==0){emp[a]=1; cnt++;}
    }
    for(int i=0;i<N;i++){
      if(emp[i]==0){v.push_back(i);}
    }
  }
  else{
    vector<ll> bl(N,0);
    int cnt=0;
    while(cnt<K){
      int a=Int(0,N);
      if(bl[a]==0){bl[a]=1; cnt++;}
    }
    for(int i=0;i<N;i++){
      if(bl[i]==1){v.push_back(i);}
    }
  }
  s=v[Int(0,K)];
  t=Int(0,N);
  out(file);
  int idx=4;
  while(num[idx]=='9'){num[idx]='0'; idx--;}
  num[idx]++;
}

int main(){
  for(int i=0;i<CASE;i++){test();}
  
  return 0;
}
