#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

int w,h,t;
int sx, sy;
int dx=1;
int dy=1;
pair<int,int> next(pair<int,int> p) {
    auto[x,y] = p;
    int nx = x+dx;
    int ny = y+dy;
    if (nx==0 || nx==w) dx*=-1;
    if (ny==0 || ny==h) dy*=-1;
    return {nx, ny};
}

signed main() {
    cin >> w >> h >> t;
    cin >> sx >> sy;
    if(sx==w) dx=-1;
    if(sy==h) dy=-1;
    for (int i = 0; i < t; i++) {
        auto p = next({sx, sy});
        sx = p.first;
        sy = p.second;
    }
    cout << sx << " " << sy << endl;

    return 0;
}
