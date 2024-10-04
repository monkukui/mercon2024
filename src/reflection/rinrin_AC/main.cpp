#include <iostream>
using namespace std;

int main(){
    long long w,h,t;
    cin >> w >> h >> t;
    long long s_x, s_y;
    cin >> s_x >> s_y;

    long long ans_x, ans_y;

    if ((s_x+t) / w % 2) {
        ans_x = w - (s_x+t) % w;
    } else {
        ans_x = (s_x+t) % w;
    }

    if ((s_y+t) / h % 2) {
        ans_y = h - (s_y+t) % h;
    } else {
        ans_y = (s_y+t) % h;
    }

    cout << ans_x << " " << ans_y << endl;
}
