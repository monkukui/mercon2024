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

void dfs(vector<ll> &B, vector<vector<ll>> &connection, ll now, ll l, ll r) {
    if (now != l) {
        ll min_b = INF;
        ll min_index = -1;
        for (ll i = l; i < now; ++i) {
            if (min_b > B.at(i)) {
                min_b = B.at(i);
                min_index = i;
            }
        }
        connection.at(now).push_back(min_index);
        dfs(B, connection, min_index, l, now - 1);
    }
    if (now != r) {
        ll min_b = INF;
        ll min_index = -1;
        for (ll i = now + 1; i <= r; ++i) {
            if (min_b > B.at(i)) {
                min_b = B.at(i);
                min_index = i;
            }
        }
        connection.at(now).push_back(min_index);
        dfs(B, connection, min_index, now + 1, r);
    }
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
    vector<ll> B(M);
    st = {};
    vector<ll> B_index(M);
    for (ll i = 0; i < M; ++i) {
        cin >> B.at(i);
        st.insert(B.at(i));
        B_index.at(B.at(i) - 1) = i;
    }
    assert(st.size() == M);
    vector<vector<ll>> connection(M);
    ll root;
    for (ll i = 0; i < M; ++i) {
        if (B.at(i) == 1) {
            root = i;
        }
    }
    dfs(B, connection, root, 0, M - 1);

    euler_tour et(connection, root);
    vector<pll> check_order(M);
    for (ll i = 0; i < M; ++i) {
        check_order.at(i) = {et.in.at(i), i};
    }
    sort(check_order.rbegin(), check_order.rend());
    vector<vector<pll>> dp(N, vector<pll>(M, {-INF, INF}));
    for (ll i = 0; i < M; ++i) {
        ll b_index = check_order.at(i).second;
        for (ll j = 0; j < N; ++j) {
            ll l = j;
            ll r = j;
            for (ll ci = 0; ci < connection.at(b_index).size(); ++ci) {
                if (connection.at(b_index).at(ci) == et.par.at(b_index)) {
                    continue;
                }
                ll next = connection.at(b_index).at(ci);
                if (next < b_index) {
                    l = -INF;
                    for (ll k = 0; k < j; ++k) {
                        if (A.at(k) < A.at(j)) {
                            continue;
                        }
                        if (dp.at(k).at(next).second < j) {
                            l = max(l, dp.at(k).at(next).first);
                        }
                    }
                }
                if (next > b_index) {
                    r = INF;
                    for (ll k = j + 1; k < N; ++k) {
                        if (A.at(k) < A.at(j)) {
                            continue;
                        }
                        if (j < dp.at(k).at(next).first) {
                            r = min(r, dp.at(k).at(next).second);
                        }
                    }
                }
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
