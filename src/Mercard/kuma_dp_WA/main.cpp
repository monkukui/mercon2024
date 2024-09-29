#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#include <map>
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
    vector<ll> dp(2 * X + 1, INF);// dp[100] = 合計が100の時の最小損失ポイント
    dp.at(0) = 0;
    for (ll i = 0; i < N; ++i) {
        ll a = A.at(i);
        for (ll j = 0; j < 2 * X + 1; ++j) {
            ll now = j / X;
            ll next = (j + a) / X;
            // ポイント損失が発生
            if (now != next) {
                ll loss = (j + a) - (((j + a) / X) * X);
                dp.at(min(2 * X, j + a)) = min(dp.at(min(2 * X, j + a)), dp.at(j) + loss);
            }
            else {
                dp.at(min(2 * X, j + a)) = min(dp.at(min(2 * X, j + a)), dp.at(j));
            }
        }
    }
    cout << max_point - dp.at(min(sum, 2 * X)) << endl;
}
