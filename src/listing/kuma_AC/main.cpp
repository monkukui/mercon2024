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
        if (S == "on_sale") {
            if (P >= C) {
                ok = false;
            }
        }
        if (S == "sold_out") {
            if (C >= P) {
                ok = false;
            }
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
