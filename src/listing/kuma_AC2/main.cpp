#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define ll long long
using namespace std;

int main() {
    ll N, P;
    cin >> N >> P;
    bool ok = true;
    for (ll i = 0; i < N; ++i) {
        ll C;
        string S;
        cin >> C >> S;
        if (C < P) {
            if (S != "sold_out") {
                ok = false;
            }
        }
        else if (C > P) {
            if (S != "on_sale") {
                ok = false;
            }
        }
        else {
            ok = false;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
