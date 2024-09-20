#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<vector<vector<bool>>>> dp(n + 1, vector<vector<vector<bool>>>(2 * x, vector<vector<bool>>(2 * x, vector<bool>(2 * x, false))));
    dp[0][0][0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j1 = 0; j1 < 2 * x; j1++) {
            for (int j2 = 0; j2 < 2 * x; j2++) {
                for (int j3 = 0; j3 < 2 * x; j3++) {
                    if (!dp[i][j1][j2][j3]) continue;
                    // 取らない
                    dp[i + 1][j1][j2][j3] = true;

                    if (j1 + a[i] < 2 * x) dp[i + 1][j1 + a[i]][j2][j3] = true;
                    if (j2 + a[i] < 2 * x) dp[i + 1][j1][j2 + a[i]][j3] = true;
                    if (j3 + a[i] < 2 * x) dp[i + 1][j1][j2][j3 + a[i]] = true;
                }
            }
        }
    }

    int ans = inf;
    for (int j1 = 0; j1 < 2 * x; j1++) {
        for (int j2 = 0; j2 < 2 * x; j2++) {
            for (int j3 = 0; j3 < 2 * x; j3++) {
                if (!dp[n][j1][j2][j3]) continue;

                int cost = 0;
                bool valid = true;
                int sum = 0;
                for (auto amount : [j1, j2, j3]) {
                    sum += amount;
                    if (sum < x) {
                        valid = false;
                        break;
                    }
                    cost += (sum - x);
                    sum -= x;
                }

                if (valid) chmin(ans, cost);
            }
        }
    }

    ans = -ans;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    for (int j = 1; j <= 4; j++) {
        if (sum < x) {
            ans += j * sum;
            break;
        } else {
            ans += j * x;
            sum -= x;
        }
    }

    cout << ans << endl;

    return 0;
}
