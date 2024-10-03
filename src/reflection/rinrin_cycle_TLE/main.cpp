#include <iostream>
#include <map>
using namespace std;

int main(){
    long long w,h,t;
    cin >> w >> h >> t;
    long long s_x, s_y;
    cin >> s_x >> s_y;

    long long n_x = s_x;
    long long n_y = s_y;
    long long n_t = 0;

    int x_d = 1;
    int y_d = 1;  

    do{
        if (abs(s_x) == w || (n_t != 0 &&s_x == 0)){
            x_d *= -1;
        } 
        if (abs(s_y) == h || (n_t != 0 && s_y == 0)){
            y_d *= -1;
        }
        s_x += x_d;
        s_y += y_d;
        n_t ++;

        if (n_x == s_x && n_y == s_y && x_d == 1 && x_d == 1){
            break;
        }
        
    }while(n_t < t);

    if (n_t == t){
        cout << s_x << " " << s_y << endl;
        return 0;  
    } 

    t = t % n_t;
    do{
        if (abs(s_x) == w || (n_t != 0 &&s_x == 0)){
            x_d *= -1;
        } 
        if (abs(s_y) == h || (n_t != 0 && s_y == 0)){
            y_d *= -1;
        }
        s_x += x_d;
        s_y += y_d;
        n_t ++;
        
    }while(n_x == s_x && n_y == s_y && x_d == 1 && x_d == 1 && n_t < t);
    cout << s_x << " " << s_y << endl;
}