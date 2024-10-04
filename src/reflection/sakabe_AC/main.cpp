#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

int w,h,t;
int sx, sy;


int f(int now, int max, int d){
    int nokori = max - now;
    if(nokori > d){
        return now + d;
    }
    d -= nokori;
    if(d <= max){
        return max - d;
    }
    d -= max;
    return d;
}

signed main() {
    cin >> w >> h >> t;
    cin >> sx >> sy;

    int tx = t % (2 * w);
    int ty = t % (2 * h);

    int gx = f(sx, w, tx);
    int gy = f(sy, h, ty);

    cout << gx << " " << gy << endl;

    return 0;
}
