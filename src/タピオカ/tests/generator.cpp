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
#include "constraints.hpp"
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

const int small_case=10;
const int rand_case=5;
const int max_case=3;
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

// ll N;
vector<ll> A;

void out(string file){
  ofstream ofs(file,ios::out);
  ofs<<N<<endl;
  ofs<<A<<endl;
  ofs.close();
}

void small(){
  static string num="00000";
  string file="10_small_"+num+".in";
  N=Int(MIN_N,10);
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=Int(MIN_A,N-i+1);
  }
  out(file);
  int idx=4;
  while(num[idx]=='9'){num[idx]='0'; idx--;}
  num[idx]++;
}

void Rand(){
  static string num="00000";
  string file="20_rand_"+num+".in";
  N=Int(MIN_N,MAX_N+1);
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=Int(MIN_A,N-i+1);
  }
  out(file);
  int idx=4;
  while(num[idx]=='9'){num[idx]='0'; idx--;}
  num[idx]++;
}

void maximum(){
  static string num="00000";
  string file="30_Max_"+num+".in";
  N=MAX_N;
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=Int(MIN_A,N-i+1);
  }
  out(file);
  int idx=4;
  while(num[idx]=='9'){num[idx]='0'; idx--;}
  num[idx]++;
}

void critical_00(){
  string file="90_critical_00.in";
  N=MAX_N;
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=MIN_A;
  }
  out(file);
}

void critical_01(){
  string file="90_critical_01.in";
  N=MAX_N;
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=N-i;
  }
  out(file);
}

void critical_02(){
  string file="90_critical_02.in";
  N=MIN_N;
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=MIN_A;
  }
  out(file);
}

void critical_03(){
  string file="90_critical_03.in";
  N=MIN_N;
  A.resize(N);
  for(int i=0;i<N;i++){
    A[i]=N-i;
  }
  out(file);
}

int main(){
  for(int i=0;i<small_case;i++){small();}
  for(int i=0;i<rand_case;i++){Rand();}
  for(int i=0;i<max_case;i++){maximum();}
  critical_00();
  critical_01();
  critical_02();
  critical_03();
  
  
  return 0;
}
