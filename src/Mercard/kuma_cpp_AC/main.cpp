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

    vector<vector<int>> dp(2 * X, vector<int>(2 * X, -1));
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        int a = A[i];
        for (int j = 2 * X - 1; j >= 0; j--) {
            for (int k = 2 * X - 1; k >= 0; k--) {
                if (dp[j][k] == -1) {
                    continue;
                }
                if (j < X) {
                    dp[j + a][k] = max(dp[j + a][k], dp[j][k] + a);
                }
                if (k < X) {
                    dp[j][k + a] = max(dp[j][k + a], dp[j][k] + a * 2);
                }
            }
        }
    }

    int sum_a = accumulate(A.begin(), A.end(), 0);
    int ans = 0;
    for (int i = 0; i < 2 * X; i++) {
        ans = max(ans, dp[i][0]);
        if (i >= X) {
            for (int j = 0; j < 2 * X; j++) {
                ans = max(ans, dp[i][j]);
                if (j + i >= 2 * X && dp[i][j] != -1) {
                    ans = max(ans, dp[i][j] + 3 * (sum_a - i - j));
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
