#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <set>
#include <map>
#include <queue>
#define ll long long
#define pll pair<ll, ll>
#define INF 100000000000
using namespace std;

ll N, M;

int main() {
    cin >> N >> M;
    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    vector<ll> X(M - 1), Y(M - 1);
    for (ll i = 0; i < M - 1; ++i) {
        cin >> X.at(i) >> Y.at(i);
        X.at(i) -= 1, Y.at(i) -= 1;
    }
    ll P = 30;
    if (N > P) {
        ll cnt = 0;
        while (true) {
            cnt += 1;
        }
    }
    vector<ll> power(P + 1, 1);
    for (ll i = 0; i < P; ++i) {
        power.at(i + 1) = power.at(i) * 2;
    }
    bool found = false;
    for (ll i = 0; i < power.at(N); ++i) {
        ll now = i;
        if (__builtin_popcount(now) != M) {
            continue;
        }
        vector<ll> B;
        for (ll j = 0; j < N; ++j) {
            if ((power.at(j) & now) != 0) {
                B.push_back(A.at(j));
            }
        }
        bool ok = true;
        for (ll j = 0; j < M - 1; ++j) {
            if (!(B.at(X.at(j)) < B.at(Y.at(j)))) {
                ok = false;
            }
        }
        if (ok) {
            found = true;
        }
    }
    if (found) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
