#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<vector<int>>> dp(2 * X, vector<vector<int>>(2 * X, vector<int>(2 * X, -1)));
    dp[0][0][0] = 0;

    for (int i = 0; i < N; i++) {
        int a = A[i];
        for (int j = 2 * X - 1; j >= 0; j--) {
            for (int k = 2 * X - 1; k >= 0; k--) {
                for (int l = 2 * X - 1; l >= 0; l--) {
                    if (dp[j][k][l] == -1) {
                        continue;
                    }
                    if (j < X) {
                        dp[j + a][k][l] = max(dp[j + a][k][l], dp[j][k][l] + a);
                    }
                    if (k < X) {
                        dp[j][k + a][l] = max(dp[j][k + a][l], dp[j][k][l] + a * 2);
                    }
                    if (l < X) {
                        dp[j][k][l + a] = max(dp[j][k][l + a], dp[j][k][l] + a * 3);
                    }
                }
            }
        }
    }

    int sum_a = accumulate(A.begin(), A.end(), 0);
    int ans = 0;
    for (int i = 0; i < 2 * X; i++) {
        ans = max(ans, dp[i][0][0]);
        if (i >= X) {
            for (int j = 0; j < 2 * X; j++) {
                ans = max(ans, dp[i][j][0]);
                if (j >= X) {
                    for (int k = 0; k < 2 * X; k++) {
                        ans = max(ans, dp[i][j][k]);
                        if (k >= X && dp[i][j][k] != -1) {
                            ans = max(ans, dp[i][j][k] + 4 * (sum_a - i - j - k));
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
