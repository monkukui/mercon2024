#include<bits/stdc++.h>
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

const ll MAX=16;
ll N,M,K,S,T;
vector<ll> V;
vector<vector<ll>> edge;

int dp[MAX][1<<MAX];

void input(){
  cin>>N>>M;
  edge.resize(N,vector<ll>(N));
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--; b--;
    edge[a][b]=edge[b][a]=1;
  }
  cin>>K;
  V.resize(K);
  cin>>V>>S>>T; S--; T--;
  for(auto &I:V){I--;}
}

void solve(){
  input();
  queue<pll> Q;
  {
    int k=0;
    for(auto &I:V){k|=1<<I;}
    dp[S][k]=true;
    Q.push({S,k});
  }
  while(!Q.empty()){
    int a=Q.front().F,b=Q.front().S; Q.pop();
    for(int i=0;i<N;i++){
      if((b>>i&1)==0 || i==a){continue;}
      for(int j=0;j<N;j++){
        if((b>>j&1)!=0 || edge[i][j]==0){continue;}
        int nx=b^(1<<i)^(1<<j);
        if(!dp[a][nx]){
          dp[a][nx]=true;
          Q.push({a,nx});
        }
      }
    }
    for(int j=0;j<N;j++){
      if((b>>j&1)!=0 || edge[a][j]==0){continue;}
      int nx=b^(1<<a)^(1<<j);
      if(!dp[j][nx]){
        dp[j][nx]=true;
        Q.push({j,nx});
      }
    }
  }
  for(int i=0;i<1<<MAX;i++){
    if(dp[T][i]){cout<<"Yes"<<endl; return;}
  }
  cout<<"No"<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();

  return 0;
}
