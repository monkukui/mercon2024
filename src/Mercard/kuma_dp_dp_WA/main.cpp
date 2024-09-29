#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#define INF 5000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;

vector<ll> A;
ll N, X;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> X;
    A = vector<ll>(N);
    ll sum = 0;
    for (ll i = 0; i < N; ++i) {
        cin >> A.at(i);
        sum += A.at(i);
    }
    ll max_point = 0;
    if (sum <= X) {
        max_point = sum;
    }
    else if (sum <= 2 * X) {
        max_point = sum + (sum - X);
    }
    else {
        max_point = sum + (sum - X) + (sum - 2 * X);
    }
    vector<vector<ll>> dp1(2 * X + 1);// dp1[i] = 合計iになるように使ったAのindexの集合
    vector<ll> dp2(2 * X + 1, INF);// dp2[i] = 合計iを作るにあたって失ったポイント
    vector<ll> can_use;
    for (ll i = 0; i < N; ++i) {
        can_use.push_back(i);
    }
    dp1.at(0) = {};
    dp2.at(0) = 0;
    ll diff = 0;
    for (ll i = 0; i < can_use.size(); ++i) {
        ll index = can_use.at(i);
        ll a = A.at(index);
        for (ll j = 0; j + diff < 2 * X; ++j) {
            if (dp2.at(j + diff) == INF) {
                continue;
            }
            ll now = (j + diff) / X;
            ll next = (j + a + diff) / X;
            // ポイント損失が発生
            if (now != next) {
                ll loss = (j + a + diff) - (((j + a + diff) / X) * X);
                if (dp2.at(min(2 * X, j + a + diff)) > dp2.at(j + diff) + loss) {
                    dp2.at(min(2 * X, j + a + diff)) = min(dp2.at(min(2 * X, j + a + diff)), dp2.at(j + diff) + loss);
                    dp1.at(min(2 * X, j + a + diff)) = dp1.at(j + diff);
                    dp1.at(min(2 * X, j + a + diff)).push_back(index);
                }
            }
            else {
                if (dp2.at(min(2 * X, j + a + diff)) > dp2.at(j + diff)) {
                    dp2.at(min(2 * X, j + a + diff)) = min(dp2.at(min(2 * X, j + a + diff)), dp2.at(j + diff));
                    dp1.at(min(2 * X, j + a + diff)) = dp1.at(j + diff);
                    dp1.at(min(2 * X, j + a + diff)).push_back(index);
                }
            }
        }
    }
    ll ans = 0;
    if (sum <= X) {
        cout << sum << endl;
        return 0;
    }
    if (sum <= 2 * X) {
        for (ll i = X ; i < 2 * X + 1; ++i) {
            ans = max(ans, max_point - (dp2.at(i)));
        }
        cout << ans << endl;
        return 0;
    }
    ll loss2 = INF;
    for (ll sum1 = X; sum1 < 2 * X + 1; ++sum1) {
        if (dp2.at(sum1) == INF) {
            continue;
        }
        can_use = {};
        diff = sum1;
        for (ll i = 0; i < N; ++i) {
            bool in_dp1 = false;
            for (ll j = 0; j < dp1.at(sum1).size(); ++j) {
                if (dp1.at(sum1).at(j) == i) {
                    in_dp1 = true;
                    break;
                }
            }
            if (!in_dp1) {
                can_use.push_back(i);
            }
        }
        vector<ll> dp2_(2 * X + 1, INF);// dp2[i] = 合計iを作るにあたって失ったポイント
        dp2_.at(0) = 0;
        for (ll i = 0; i < can_use.size(); ++i) {
            ll index = can_use.at(i);
            ll a = A.at(index);
            for (ll j = 0; j + diff < 2 * X; ++j) {
                if (dp2_.at(j + diff) == INF) {
                    continue;
                }
                ll now = (j + diff) / X;
                ll next = (j + a + diff) / X;
                // ポイント損失が発生
                if (now != next) {
                    ll loss = (j + a + diff) - (((j + a + diff) / X) * X);
                    if (dp2_.at(min(2 * X, j + a + diff)) > dp2_.at(j + diff) + loss) {
                        dp2_.at(min(2 * X, j + a + diff)) = min(dp2_.at(min(2 * X, j + a + diff)), dp2_.at(j + diff) + loss);
                    }
                }
                else {
                    if (dp2_.at(min(2 * X, j + a + diff)) > dp2_.at(j + diff)) {
                        dp2_.at(min(2 * X, j + a + diff)) = min(dp2_.at(min(2 * X, j + a + diff)), dp2_.at(j + diff));
                    }
                }
            }
        }
        for (ll i = max(0ll, 2 * X - diff); i < 2 * X + 1; ++i) {
            ans = max(ans, max_point - (dp2.at(sum1) + dp2_.at(i)));
        }
    }
    cout << ans << endl;
}
