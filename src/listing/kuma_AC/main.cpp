#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#define ll long long
using namespace std;

int main() {
    ll N, P;
    cin >> N >> P;
    assert((2 <= N) && (N <= 100));
    assert((300 <= P) && (P <= 9999999));
    bool ok = true;
    for (ll i = 0; i < N; ++i) {
        ll C;
        string S;
        cin >> C >> S;
        assert((300 <= C) && (C <= 9999999));
        assert((S == "on_sale") || (S == "sold_out"));
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
