#include <iostream>
using namespace std;
#define INIT ios::sync_with_stdio(false);cin.tie(0);
#define min(a, b) (a < b ? a : b)

int main() {
    INIT;

    long long w, h, t;
    cin >> w >> h >> t;
    long long sx, sy;
    cin >> sx >> sy;

    long long x = (sx + t) % (2 * w);
    long long y = (sy + t) % (2 * h);

    long long ansx = min(x, 2 * w - x);
    long long ansy = min(y, 2 * h - y);
    cout << ansx << " " << ansy << endl;

    return 0;
}