#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1), ord(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ord[i] = i+a[i]-1;
        if (ord[i] > n) ord[i] = n;
    }

    sort(ord.begin(), ord.end());
    int64_t ans = 1;
    for (int i = 1; i <= n; i++) {
        ans *= ord[i]-i+1;
        ans %= mod;
    }

    cout << ans << '\n';
    return 0;
}
