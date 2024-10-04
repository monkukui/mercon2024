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

ll N, M;

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
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    vector<ll> B(M);
    ll root = 0;
    for (ll i = 0; i < M; ++i) {
        cin >> B.at(i);
        if (B.at(i) == 1) {
            root = i;
        }
    }
    vector<vector<ll>> connection_B(M);
    dfs(B, connection_B, root, 0, M - 1);
    ll P = 30;
    if (N > P) {
        ll cnt = 0;
        while (true) {
            cnt += 1;
        }
    }
    vector<ll> power(P + 1, 1);
    for (ll i = 0; i < P; ++i) {
        power.at(i + 1) = power.at(i) * 2;
    }
    bool found = false;
    for (ll i = 0; i < power.at(N); ++i) {
        ll now = i;
        if (__builtin_popcount(now) != M) {
            continue;
        }
        vector<ll> new_A;
        for (ll j = 0; j < N; ++j) {
            if ((power.at(j) & now) != 0) {
                new_A.push_back(A.at(j));
            }
        }
        ll root_A = -1;
        ll min_A = INF;
        for (ll j = 0; j < M; ++j) {
            if (new_A.at(j) < min_A) {
                min_A = new_A.at(j);
                root_A = j;
            }
        }
        vector<vector<ll>> connection_A(M);
        dfs(new_A, connection_A, root_A, 0, M - 1);
        if (connection_B == connection_A) {
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
