#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#define ll long long
#define pll pair<ll, ll>
#define INF 100000000000
using namespace std;

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
struct max_segment_tree {
  int MAX_N;
  ll N;
  int nn;
  vector<ll> dat;
  max_segment_tree(ll n_) {
    N = n_;
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
    MAX_N = nn;
    dat = vector<ll>(2 * MAX_N - 1, -INF);
  }

  void update(ll k, ll a) {
    assert(0 <= k && k < N);
    k += nn - 1;
    dat.at(k) = max(dat.at(k), a);//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = max(dat.at(k * 2 + 1), dat.at(k * 2 + 2));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
    assert(0 <= a && a < N && 0 <= b && b <= N);
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = nn;
    }
    if (r <= a || b <= l) {
      return -INF;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return max(vl, vr);//要変更
    }
  }
};

struct min_segment_tree {
  int MAX_N;
  ll N;
  int nn;
  vector<ll> dat;
  min_segment_tree(ll n_) {
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
    dat.at(k) = min(dat.at(k), a);//要変更
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

ll N, M;
bool is_tree(vector<vector<ll>> &connection) {
    queue<ll> q;
    q.push(0);
    vector<ll> already(M, false);
    already.at(0) = true;
    while (!q.empty()) {
        ll now = q.front();
        q.pop();
        for (ll i = 0; i < connection.at(now).size(); ++i) {
            ll next = connection.at(now).at(i);
            if (already.at(next)) {
                continue;
            }
            already.at(next) = true;
            q.push(next);
        }
    }
    bool res = true;
    for (ll i = 0; i < M; ++i) {
        if (!already.at(i)) {
            res = false;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    cin >> N >> M;
    assert((1 <= N) && (N <= 5000));
    assert((1 <= M) && (M <= N));
    vector<ll> A(N);
    set<ll> st;
    for (ll i = 0; i < N; ++i) {
        cin >> A.at(i);
        st.insert(A.at(i));
    }
    assert(st.size() == N);
    vector<ll> X(M - 1), Y(M - 1);
    map<ll, bool> y_already;
    map<ll, ll> x_cnt;
    vector<vector<ll>> connection(M);
    for (ll i = 0; i < M - 1; ++i) {
        cin >> X.at(i) >> Y.at(i);
        assert((1 <= X.at(i)) && (X.at(i) <= M));
        assert((1 <= Y.at(i)) && (Y.at(i) <= M));
        X.at(i) -= 1, Y.at(i) -= 1;
        connection.at(X.at(i)).push_back(Y.at(i));
        connection.at(Y.at(i)).push_back(X.at(i));
        assert(X.at(i) != Y.at(i));
        if (x_cnt.find(X.at(i)) == x_cnt.end()) {
            x_cnt[X.at(i)] = 0;
        }
        x_cnt[X.at(i)] += 1;
        assert(x_cnt[X.at(i)] < 3);
        assert(y_already.find(Y.at(i)) == y_already.end());
        y_already[Y.at(i)] = true;
    }
    if (!is_tree(connection)) {
        cout << "No" << endl;
        return 0;
    }
    ll root;
    for (ll i = 0; i < M; ++i) {
        if (y_already.find(i) == y_already.end()) {
            root = i;
        }
    }

    euler_tour et(connection, root);
    vector<pll> check_order(M);
    for (ll i = 0; i < M; ++i) {
        check_order.at(i) = {et.in.at(i), i};
    }
    sort(check_order.rbegin(), check_order.rend());
    vector<pll> a_check_order(N);
    for (ll i = 0; i < N; ++i) {
        a_check_order.at(i) = {A.at(i), i};
    }
    sort(a_check_order.rbegin(), a_check_order.rend());

    vector<min_segment_tree> rseg;
    vector<max_segment_tree> lseg;
    for (ll i = 0; i < M; ++i) {
        rseg.push_back(min_segment_tree(N));
        lseg.push_back(max_segment_tree(N));
    }
    vector<vector<pll>> dp(N, vector<pll>(M, {-INF, INF}));
    for (ll a_j = 0; a_j < N; ++a_j) {
        ll j = a_check_order.at(a_j).second;
        for (ll i = 0; i < M; ++i) {
            ll b_index = check_order.at(i).second;
            ll l = j;
            ll r = j;
            for (ll ci = 0; ci < connection.at(b_index).size(); ++ci) {
                if (connection.at(b_index).at(ci) == et.par.at(b_index)) {
                    continue;
                }
                ll next = connection.at(b_index).at(ci);
                if (next < b_index) {
                    l = INF;
                    l = lseg.at(next).query(0, j);
                }
                if (next > b_index) {
                    r = INF;
                    if (j + 1 != N) {
                        r = rseg.at(next).query(j + 1, N);
                    }
                }
            }
            if (l != -INF && r != INF) {
                lseg.at(b_index).update(r, l);
                rseg.at(b_index).update(l, r);
            }
            dp.at(j).at(b_index) = {l, r};
        }
    }
    bool found = false;
    for (ll i = 0; i < N; ++i) {
        if ((dp.at(i).at(check_order.at(M - 1).second).first != -INF) && (dp.at(i).at(check_order.at(M - 1).second).second != INF)) {
            found = true;
        }
    }
    if (found) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
