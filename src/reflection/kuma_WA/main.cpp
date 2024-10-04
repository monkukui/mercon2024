#include <iostream>
#include <cassert>
#define ll long long
using namespace std;

ll calc(ll s, ll T, ll M) {
    T %= (2 * M);
    s += T;
    if (s >= M) {
        s = M - (s - M);
    }
    // if (s <= 0) {
    //     s *= -1;
    // }
    return s;
}

int main(){
    ll W, H, T;
    cin >> W >> H >> T;
    ll max_WHT = 1;
    for (ll i = 0; i < 12; ++i) {
        max_WHT *= 10;
    }
    assert((1 <= W) && (W <= max_WHT));
    assert((1 <= H) && (H <= max_WHT));
    assert((1 <= T) && (T <= max_WHT));
    ll sx, sy;
    cin >> sx >> sy;
    assert((0 <= sx) && (sx <= W));
    assert((0 <= sy) && (sy <= H));
    cout << calc(sx, T, W) << ' ' << calc(sy, T, H) << endl;
}
