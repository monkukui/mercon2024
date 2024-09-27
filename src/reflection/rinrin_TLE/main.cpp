#include <iostream>
using namespace std;

int main(){
    long long w,h,t;
    cin >> w >> h >> t;
    long long s_x, s_y;
    cin >> s_x >> s_y;

    int x_d = 1;
    int y_d = 1;
    for(int i = 0; i < t; i++){
        if (abs(s_x) == w || (i != 0 &&s_x == 0)){
            x_d *= -1;
        } 
        if (abs(s_y) == h || (i != 0 && s_y == 0)){
            y_d *= -1;
        }
        s_x += x_d;
        s_y += y_d;
    }
    cout << s_x << " " << s_y << endl;
    
}