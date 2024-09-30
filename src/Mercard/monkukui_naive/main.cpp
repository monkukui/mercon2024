#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }

    int ans = 0;
    do {
        int tmp = 0;
        int point = 1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[p[i]]; // 購入
            tmp += point * a[p[i]];
            if (sum >= x) {
                sum -= x;
                if (point < 3) point++;
            }
        }
        if (ans < tmp) ans = tmp;
    } while (next_permutation(p.begin(), p.end()));
    cout << ans << endl;

    return 0;
}
