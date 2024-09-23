#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;


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

    int ans = 0;
    int sum_a = 0;
    for (int i = 0; i < n; i++) sum_a += a[i];

    for (int j1 = 0; j1 < 2 * x; j1++) {
        for (int j2 = 0; j2 < 2 * x; j2++) {
            for (int j3 = 0; j3 < 2 * x; j3++) {
                if (!dp[n][j1][j2][j3]) continue;

                bool is_valid = true;
                vector<int> b = {j1, j2, j3, sum_a - j1 - j2 - j3};

                int amount = 0;
                for (int i = 0; i < 4; i++) {
                    int e = b[i];
                    amount += e;
                    if (e < x) {
                        // 後続で一つでも 1 以上があるとだめ
                        for (int j = i + 1; j < 4; j++) {
                            if (b[j] > 0) {
                                is_valid = false;
                                break;
                            }
                        }
                        if (!is_valid) break;
                    }
                    amount -= x;
                }

                if (!is_valid) continue;
                int point = j1 * 1 + j2 * 2 + j3 * 3 + (sum_a - j1 - j2 - j3) * 4;
                if (ans < point) ans = point;
            }
        }
    }

    cout << ans << endl;


    return 0;
}
