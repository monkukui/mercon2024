#include <iostream>
#include <cassert>
#define ll long long
using namespace std;

int main(){
    ll W, H, T;
    cin >> W >> H >> T;
    ll sx, sy;
    cin >> sx >> sy;
    ll a = 1, b = 1;
    for (ll i = 0; i < T; ++i) {
        ll nx = sx + a, ny = sy + b;
        if (nx < 0 || W < nx) {
            a = -a;
        }
        if (ny < 0 || H < ny) {
            b = -b;
        }
        sx += a, sy += b;
    }
    cout << sx << ' ' << sy << endl;
}
