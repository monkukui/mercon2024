#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define INF 500000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

// ============union_find_tree===============
struct union_find {
  vector<ll> par;
  vector<ll> tree_rank;
  vector<ll> num;

  union_find(ll n)
  {
    par = vector<ll>(n);
    num = vector<ll>(n, 1);
    tree_rank = vector<ll>(n);
    for (ll i = 0; i < n; ++i)
    {
      par.at(i) = i;
      tree_rank.at(i) = 0;
    }
  }

  ll find(ll x)
  {
    if (par.at(x) == x)
    {
      return x;
    }
    else
    {
      return par.at(x) = find(par.at(x));
    }
  }

  ll get_num(ll x) {
    return num.at(find(x));
  }

  void unite(ll x, ll y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
    {
      return;
    }
    if (tree_rank.at(x) < tree_rank.at(y))
    {
      par.at(x) = y;
      num.at(y) = num.at(x) + num.at(y);
    }
    else
    {
      par.at(y) = x;
      num.at(x) = num.at(x) + num.at(y);
      if (tree_rank.at(x) == tree_rank.at(y))
      {
        tree_rank.at(x)++;
      }
    }
  }

  bool same(ll x, ll y)
  {
    return find(x) == find(y);
  }
};
// =======================================

//=============euler_tour============================
//euler_tour et(connection, root);

// output:
  //et.in.at(i)
    //頂点iに最初に訪れたタイミング
  //et.out.at(i)
    //頂点iを離れるタイミング
  //et.depth.at(i)
    //頂点iと根との距離
  //et.par.at(i)
    //頂点iの親、rootの親は-1
struct euler_tour {
  vector<ll> in, out, depth, par, child_num;
  ll dist = 0;
  euler_tour(vector<vector<ll>> &connection, ll s) {
    in = out = depth = par = child_num = vector<ll>(connection.size(), -1);
    dfs(connection, s);
  }
  void dfs(vector<vector<ll>> &connection, ll now) {
    in.at(now) = dist;
    dist += 1;
    for (ll i = 0; i < connection.at(now).size(); ++i) {
      ll next = connection.at(now).at(i);
      if (next == par.at(now)) {
        continue;
      }
      depth.at(next) = depth.at(now) + 1;
      par.at(next) = now;
      dfs(connection, next);
      if (child_num.at(next) + 1 > child_num.at(now)) {
        child_num.at(now) = child_num.at(next) + 1;
      }
    }
    if (child_num.at(now) < 1) {
      child_num.at(now) = 1;
    }
    out.at(now) = dist;
    dist += 1;
  }
};
// =======================================

//=============segment_tree============================
//segment_tree seg(N);
  //ノード数Nの初期化
  //計算量 O(N)

//MAX_N
  //最大ノード数

// update(ll k, ll a)
  //k番目の値をaに更新
  //計算量 O(log(N))

// query(ll a, ll b, ll k, ll l, ll r)
  //[a, b)の最小値を求めるとき
    //query(a, b)とする
//a,b, k, l, r  はすべて0indexである
  //計算量 O(log(N))


//子ノードはdat[n〜]

struct segment_tree {
  int MAX_N;
  ll N;
  int nn;
  vector<ll> dat;
  segment_tree(ll n_) {
    N = n_;
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
    MAX_N = nn;
    dat = vector<ll>(2 * MAX_N - 1, INF);
  }

  void update(ll k, ll a) {
    assert(0 <= k && k < N);
    k += nn - 1;
    dat.at(k) = a;//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = min(dat.at(k * 2 + 1), dat.at(k * 2 + 2));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
    assert(0 <= a && a < N && 0 <= b && b <= N);
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = nn;
    }
    if (r <= a || b <= l) {
      return INF;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);//要変更
    }
  }
};
//=================================================

int main() {
  ll N, K;
  cin >> N >> K;
  assert(1 <= N && N <= 200000);
  assert(1 <= K && K <= N);
  vector<vector<ll>> connection(N);
  union_find uf(N);
  bool is_tree = true;
  for (ll i = 0; i < N - 1; ++i) {
    ll U, V;
    cin >> U >> V;
    assert(1 <= U && U < V);
    assert(U < V && V <= N);
    U -= 1, V -= 1;
    if (uf.same(U, V)) {
      is_tree = false;
    }
    uf.unite(U, V);
    connection.at(U).push_back(V);
    connection.at(V).push_back(U);
  }
  assert(is_tree);
  segment_tree seg(2 * N);
  euler_tour et(connection, 0);
  vector<vector<ll>> num_edge(N + 1);
  for (ll i = 0; i < N; ++i) {
    num_edge.at(et.child_num.at(i)).push_back(i);
  }
  vector<ll> X(N);
  map<ll, ll> X_index;
  set<ll> st;
  for (ll i = 0; i < N; ++i) {
    cin >> X.at(i);
    X_index[X.at(i)] = i;
    assert(1 <= X.at(i) && X.at(i) <= N);
    st.insert(X.at(i));
  }
  assert(st.size() == N);
  for (ll i = K; i <= N; ++i) {
    for (ll j = 0; j < num_edge.at(i).size(); ++j) {
      ll edge = num_edge.at(i).at(j);
      seg.update(et.in.at(edge), X.at(edge));
      seg.update(et.out.at(edge), X.at(edge));
    }
  }
  vector<ll> ans;
  ll now = -1;
  while (true) {
    for (ll i = 0; i < num_edge.at(K - (ll)ans.size()).size(); ++i) {
      ll edge = num_edge.at(K - ans.size()).at(i);
      seg.update(et.in.at(edge), X.at(edge));
      seg.update(et.out.at(edge), X.at(edge));
    }
    ll min_X;
    if (now == -1) {
      min_X = seg.query(et.in.at(0), et.out.at(0));
    }
    else {
      min_X = seg.query(et.in.at(now) + 1, et.out.at(now));
    }
    if (min_X == INF) {
      cout << -1 << endl;
      return 0;
    }
    ans.push_back(min_X);
    now = X_index[min_X];
    if (ans.size() == K) {
      break;
    }
  }
  assert(ans.size() == K);
  for (ll i = 0; i < ans.size(); ++i) {
    cout << ans.at(i);
    if (i != (ll)ans.size() - 1) {
      cout << ' ';
    }
  }
  cout << endl;
  return 0;
}
