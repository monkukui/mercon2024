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

struct edge {
  int to;
  int label;
};


::std::vector<::std::pair<int, int>> gabow_edmonds(const ::std::vector<::std::vector<int>>& gra){
  // E0 - 初期化
  int N = gra.size();
  ::std::vector<::std::vector<edge>> g(N + 1);
  ::std::vector<::std::pair<int, int>> edges;
  {
    int cnt = N + 1;
    for(int i = 0;i < N;i++){
      for(auto to : gra[i]){
        if(i < to){
          g[to + 1].push_back({i + 1, cnt});
          g[i + 1].push_back({to + 1, cnt++});
          edges.push_back({i + 1, to + 1});
        }
      }
    }
  }
  ::std::vector<int> mate(N + 1 , 0);
  ::std::vector<int> label(N + 1 , -1);
  ::std::vector<int> first(N + 1 , 0);
  ::std::queue<int> que;

  // firstの遅延評価
  ::std::function<int(int)> eval_first = [&](int x){
    if(label[first[x]] < 0) return first[x];
    first[x] = eval_first(first[x]);
    return first[x];
  };

  // サブルーチンR
  ::std::function<void(int, int)> rematch = [&](int v, int w){
    // R1
    int t = mate[v];
    mate[v] = w;
    if(mate[t] != v) return;
    // R2
    if(label[v] <= N){
      mate[t] = label[v];
      rematch(label[v] , t);
    }
    // R3
    else{
      int x = edges[label[v] - N - 1].first;
      int y = edges[label[v] - N - 1].second;
      rematch(x , y);
      rematch(y , x);
    }
  };

  ::std::function<void(int, int, int)> assignLabel = [&](int x, int y, int num){
    // L0
    int r = eval_first(x);
    int s = eval_first(y);
    int join = 0;
    if(r == s) return;
    // -numがフラグ
    label[r] = -num;
    label[s] = -num;
    while(true){
      // L1
      if(s != 0) ::std::swap(r , s);
      // L2
      r = eval_first(label[mate[r]]);
      if(label[r] == -num){
        join = r;
        break;
      }
      label[r] = -num;
    }
    // L3
    int v = first[x];
    // L4
    while(v != join){
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
    // L3
    v = first[y];
    // L4
    while(v != join){
      que.push(v);
      label[v] = num;
      first[v] = join;
      v = first[label[mate[v]]];
    }
    // L5は遅延評価しているため不要
    // L6
    return;
  };

  ::std::function<bool(int)> augment_check = [&](int u){
    // E1 後半
    first[u] = 0;
    label[u] = 0;
    que.push(u);
    while(!que.empty()){
      // E2 
      int x = que.front();
      que.pop();
      for(auto e : g[x]){
        int y = e.to;
        // E3
        if(mate[y] == 0 && y != u){
          mate[y] = x;
          rematch(x , y);
          return true;
        }
        // E4
        else if(label[y] >= 0){
          assignLabel(x , y , e.label);
        }
        // E5
        else if(label[mate[y]] < 0){
          label[mate[y]] = x;
          first[mate[y]] = y;
          que.push(mate[y]);
        }
        // E6
      }
    }
    return false;
  };

  for(int i = 1;i <= N;i++){
    // E1
    que = ::std::queue<int>();
    if(mate[i] != 0) continue;
    if(augment_check(i)){
      // E7
      ::std::fill(label.begin(), label.end(), -1);
    }
  }

  ::std::vector<::std::pair<int, int>> ans;
  for(int i = 1;i <= N;i++){
    if(i < mate[i]){
      ans.push_back({i , mate[i]});
    }
  }
  return ans;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N,rem;
  cin>>N;
  vector<pll> A(N),tmp;
  for(auto &I:A){cin>>I.F;}
  for(auto &I:A){cin>>I.S;}
  ll ans=0;
  for(auto &I:A){if(I.F<I.S){tmp.push_back(I);}}
  A=tmp;
  N=A.size();
  {
    vector<vector<int>> gra(N);
    auto add_edge=[&](int i,int j){gra[i].push_back(j); gra[j].push_back(i);};
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        if(A[i].F<=A[j].F && A[i].S<=A[j].S){add_edge(i,j);}
        else if(A[i].F>=A[j].F && A[i].S>=A[j].S){add_edge(i,j);}
      }
    }
    auto uku=gabow_edmonds(gra);
    ans+=uku.size();
    rem=N-uku.size()*2;
  }
  assert(rem>=0);
  ans+=rem/3*2+rem%3;
  cout<<ans<<endl;

  return 0;
}
