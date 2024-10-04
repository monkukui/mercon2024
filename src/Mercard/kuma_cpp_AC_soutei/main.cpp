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

    vector<vector<bool>> dp(2 * X, vector<bool>(2 * X, false));
    dp[0][0] = true;

    for (int i = 0; i < N; i++) {
        int a = A[i];
        for (int S1 = 2 * X - 1; S1 >= 0; S1--) {
            for (int S2 = 2 * X - 1; S2 >= 0; S2--) {
                if (S1 < X) {
                    dp[S1 + a][S2] = (dp[S1][S2] | dp[S1 + a][S2]);
                }
                if (S2 < X) {
                    dp[S1][S2 + a] = (dp[S1][S2] | dp[S1][S2 + a]);
                }
            }
        }
    }

    int sum_a = accumulate(A.begin(), A.end(), 0);
    for (int S1 = 0; S1 < 2 * X; ++S1) {
        for (int S2 = 0; S2 < 2 * X; ++S2) {
            if (S1 < X && 0 < S2) {
                dp[S1][S2] = false;
            }
            if (S1 + S2 < 2 * X && (sum_a - S1 - S2 != 0)) {
                dp[S1][S2] = false;
            }
        }
    }

    int ans = 0;
    for (int S1 = 0; S1 < 2 * X; ++S1) {
        for (int S2 = 0; S2 < 2 * X; ++S2) {
            if (dp[S1][S2]) {
                ans = max(ans, S1 + S2 * 2 + (sum_a - S1 - S2) * 3);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
