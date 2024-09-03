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

const int INF=1e8;

template< typename G >
struct LowLink {
  G g;
  vector< int > used, ord, low;
  vector< int > articulation;
  vector< pair< int, int > > bridge;
 
  LowLink(const G &g) : g(g) {}
 
  int dfs(int idx, int k, int par) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];
    bool is_articulation = false;
    int cnt = 0;
    for(auto &to : g[idx]) {
      if(!used[to]) {
        ++cnt;
        k = dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        is_articulation |= ~par && low[to] >= ord[idx];
        if(ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (int) to));
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
    is_articulation |= par == -1 && cnt > 1;
    if(is_articulation) articulation.push_back(idx);
    return k;
  }
 
  virtual void build() {
    used.assign(g.size(), 0);
    ord.assign(g.size(), 0);
    low.assign(g.size(), 0);
    int k = 0;
    for(int i = 0; i < g.size(); i++) {
      if(!used[i]) k = dfs(i, k, -1);
    }
  }
};

template< typename G >
struct TwoEdgeConnectedComponents : LowLink< G > {
  using LL = LowLink< G >;
  vector< int > comp;
  
  TwoEdgeConnectedComponents(const G &g=G()) : LL(g) {}
 
  int operator[](const int &k) {
    return comp[k];
  }
 
  void dfs(int idx, int par, int &k) {
    if(~par && this->ord[par] >= this->low[idx]) comp[idx] = comp[par];
    else comp[idx] = k++;
    for(auto &to : this->g[idx]) {
      if(comp[to] == -1) dfs(to, idx, k);
    }
  }
 
  void build(vector<vector<ll>> &t) {
    LL::build();
    comp.assign(this->g.size(), -1);
    int k = 0;
    for(int i = 0; i < comp.size(); i++) {
      if(comp[i] == -1) dfs(i, -1, k);
    }
    t.resize(k);
    for(auto &e : this->bridge) {
      int x = comp[e.first], y = comp[e.second];
      t[x].push_back(y);
      t[y].push_back(x);
    }
  }
};

ll N,M,SZ;
vector<vector<ll>> edge1,edge2;
vector<int> block;
vector<int> sz,bl,cl;
int s,t,K,S,T;

TwoEdgeConnectedComponents<vector<vector<ll>>> CC;

void input(){
  cin>>N>>M;
  edge1.resize(N);
  block.resize(N,0);
  sz.resize(N,0);
  bl.resize(N,0);
  cl.resize(N,-1);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--; b--;
    edge1[a].push_back(b);
    edge1[b].push_back(a);
  }
  cin>>K;
  for(int i=0;i<K;i++){
    int a;
    cin>>a; a--;
    block[a]=1;
  }
  cin>>s>>t;
  s--; t--;
  S=s; T=t;
}

void bfs(vector<int> &dist,int st){
  for(auto &I:dist){I=INF;}
  queue<ll> Q; 
  dist[st]=0;
  Q.push(st);
  while(!Q.empty()){
    int u=Q.front(); Q.pop();
    for(auto &v:edge2[u]){
      if(dist[v]>dist[u]+1){dist[v]=dist[u]+1; Q.push(v);}
    }
  }
}

//block oshidasu
int dfs1(int u,int p,int b=0){
  b+=bl[u];
  for(auto &v:edge2[u]){
    if(v==p){continue;}
    b=dfs1(v,u,b);
  }
  bl[u]=min(b,sz[u]);
  b-=bl[u];
  return b;
}

void dfs2(int u,int p,int c){
  cl[u]=c;
  for(auto &v:edge2[u]){
    if(v==p){continue;}
    dfs2(v,u,c);
  }
}

int dfs3(int u,int p,int l){
  l++;
  int ret=l;
  int nxl=l;
  if(sz[u]==2){chmax(ret,l+1); nxl=2;}
  for(auto &v:edge2[u]){
    if(v==p || cl[v]!=2){continue;}
    chmax(ret,dfs3(v,u,nxl));
  }
  return ret;
}

void solve(){
  input();
  if(s==t){cout<<"Yes"<<endl; return;}
  CC.g=edge1;
  CC.build(edge2);
  for(int i=0;i<N;i++){int c=CC.comp[i]; sz[c]++; chmax(SZ,c+1); bl[c]+=block[i];}
  vector<int> ds(SZ),dt(SZ);
  s=CC.comp[s]; t=CC.comp[t];
  bl[s]--;
  if(K==N){cout<<"No"<<endl; return;}
  //if(s==t){cout<<"Yes"<<endl; return;}//!!!!!!!!
  bfs(dt,t);
  {
    vector<int> con(SZ,0);
    for(auto &v:edge1[S]){
      if(CC.comp[v]!=s){con[CC.comp[v]]=1;}
    }
    for(auto &v:edge2[s]){
      if(con[v]){dfs1(v,s,0);}
      else{bl[s]=dfs1(v,s,bl[s]);}
    }
    if(bl[s]+1<sz[s]){dfs1(s,-1,0);}
    for(auto &v:edge2[s]){
      if(dt[v]>dt[s] && bl[v]<sz[v] && (con[v] || bl[s]+1<sz[s])){s=v;}
    }
    bool flag;
    do{
      flag=false;
      for(auto &v:edge2[s]){
        if(dt[v]>dt[s] && bl[v]<sz[v]){s=v; flag=true; break;}
      }
    }while(flag);
  }
  if(s==t){cout<<(K<N?"Yes":"No")<<endl; return;}
  for(auto &v:edge2[s]){if(dt[v]<dt[s]){dfs2(v,s,1);}}
  bfs(ds,s);
  int sumb=0,ept=0;
  sumb+=bl[s]; ept+=sz[s];
  for(int i=0;i<SZ;i++){
    if(cl[i]<0){continue;}
    sumb+=bl[i]; ept+=sz[i];
    if(ds[i]+dt[i]==ds[t]){cl[i]=2;}
  }
  
  for(int i=0;i<N;i++){
    if(cl[i]!=2 || i==s || i==t){continue;}
    if(edge2[i].size()>2 || sz[i]>=2){sz[i]=2;}
  }
  if(sz[s]==bl[s]+1){sz[s]=1;}
  else{sz[s]=2;}
  sz[t]=2;
  for(auto &v:edge1[T]){
    if(ds[CC.comp[v]]<ds[t]){sz[t]=1;}
  }
  int length=dfs3(s,-1,0);
  cout<<(ept>=sumb+length?"Yes":"No")<<endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  solve();


  return 0;
}
