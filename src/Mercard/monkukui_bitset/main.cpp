#include <iostream>
#include <vector>
#include <bitset>
#include <numeric>
using namespace std;

const int inf = 1e9;


int main() {

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<bitset<200>> dp(2 * x, bitset<200>(0));
    vector<bitset<200>> _dp(2 * x, bitset<200>(0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j1 = 0; j1 < 2 * x; j1++) {
            _dp[j1] |= dp[j1];

            if (j1 + a[i] < 2 * x) _dp[j1 + a[i]] |= dp[j1];

            _dp[j1] |= (dp[j1] << a[i]);
        }
        swap(dp, _dp);
    }

    int ans = 0;
    int sum_a = accumulate(a.begin(), a.end(), 0);

    for (int j1 = 0; j1 < 2 * x; j1++) {
        for (int j2 = 0; j2 < 2 * x; j2++) {
            if (!dp[j1][j2]) continue;

            bool is_valid = true;
            vector<int> b = {j1, j2, sum_a - j1 - j2};

            int amount = 0;
            for (int i = 0; i < 3; i++) {
                int e = b[i];
                amount += e;
                if (amount < x) {
                    // 後続で一つでも 1 以上があるとだめ
                    for (int j = i + 1; j < 3; j++) {
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
            int point = j1 * 1 + j2 * 2 + (sum_a - j1 - j2) * 3;
            if (ans < point) ans = point;
        }
    }

    cout << ans << endl;


    return 0;
}
