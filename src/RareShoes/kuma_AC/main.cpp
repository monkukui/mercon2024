#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

#include <random>
#include <iostream>
#include <cstdio>
#include <string>
#include <regex>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <unordered_set>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>
#include <cstddef>
#include <type_traits>
#include <vector>
#include <sys/time.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pll> XY(N);
    for (ll i = 0; i < N; ++i) {
        cin >> XY.at(i).first >> XY.at(i).second;
    }
    vector<ll> Z(M);
    for (ll i = 0; i < M; ++i) {
        cin >> Z.at(i);
    }
    sort(XY.begin(), XY.end());
    sort(Z.begin(), Z.end());
    multiset<ll> st;
    ll cnt = 0;
    ll ans = 0;
    for (ll i = 0; i < M; ++i) {
        ll z = Z.at(i);
        while (cnt != XY.size()) {
            if (XY.at(cnt).first <= z) {
                st.insert(XY.at(cnt).second);
            }
            else {
                break;
            }
            cnt += 1;
        }
        bool found = false;
        while (st.size() != 0) {
            auto itr = st.begin();
            if (*itr < z) {
                st.erase(itr);
            }
            else {
                st.erase(itr);
                found = true;
                break;
            }
        }
        if (found) {
            ans += 1;
        }
    }
    cout << ans << endl;
}
