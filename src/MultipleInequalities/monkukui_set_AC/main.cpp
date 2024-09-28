// O(nm log n) time, O(nm) space, set<pair<int, int>> 必要ないバージョン
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
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

using namespace std;
const long long int INF = numeric_limits<long long int>::max() / 4;
const int inf = numeric_limits<int>::max() / 4;
const long long int MOD1000000007 = 1000000007;
const long long int MOD998244353 = 998244353;
const double MATH_PI = 3.1415926535897932;

template<typename T1, typename T2>
inline void chmin(T1 &a, const T2 &b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, const T2 &b) { if (a < b) a = b; }

#define lint long long int
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define VI vector<int>
#define VLL vector<long long>
#define VC vector<char>
#define VB vector<bool>
#define PI pair<int, int>
#define PLL pair<long long, long long>
#define VPI vector<pair<int, int>>
#define VPLL vector<pair<long long, long long>>
#define VVI vector<vector<int>>
#define VVPI vecor<vector<pair<int, int>>>
#define VVPILL vector<vector<pair<int, long long>>>

#define SUM(v) accumulate(ALL(v), 0LL)
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))

// O(n)
template <class T, class Compare> std::vector<int> cartesian_tree(const std::vector<T>& a, Compare comp) {
    int n = a.size();
    std::vector<int> res(n), prv(n), nxt(n), stk;
    stk.reserve(n);
    for (int i = 0; i < n; ++i) {
        while (!stk.empty() && comp(a[i], a[stk.back()])) stk.pop_back();
        prv[i] = stk.empty() ? -1 : stk.back();
        stk.push_back(i);
    }
    stk.clear();
    for (int i = n; i--;) {
        while (!stk.empty() && !comp(a[stk.back()], a[i])) stk.pop_back();
        nxt[i] = stk.empty() ? n : stk.back();
        stk.push_back(i);
    }
    for (int i = 0; i < n; ++i)
        if (nxt[i] == n)
            res[i] = prv[i];
        else if (prv[i] == -1)
            res[i] = nxt[i];
        else
            res[i] = comp(a[nxt[i]], a[prv[i]]) ? prv[i] : nxt[i];
    return res;
}
template <class T> std::vector<int> cartesian_tree(const std::vector<T>& a) { return cartesian_tree(a, std::less{}); }

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    // vector<int> b(m);
    rep (i, n) {
        cin >> a[i];
        a[i]--;
    }
    // rep (i, m) {
    //     cin >> b[i];
    // }

    // auto p = cartesian_tree(b);

    vector<pair<int, int>> g(m, {-1, -1});
    vector<bool> used_y(n, false);
    for (int i = 0; i < m - 1; i++) {
        int x, y; cin >> x >> y;
        x--;
        y--;
        used_y[y] = true;
        if (x > y) g[x].first = y;
        else g[x].second = y;
    }
    // for (int i = 0; i < m; i++) {
    //     if (p[i] < 0) continue;
    //     if (i < p[i]) {
    //         g[p[i]].first = i;
    //     }
    //     if (i > p[i]) {
    //         g[p[i]].second = i;
    //     }
    // }
    int r = -1;
    for (int y = 0; y < m; y++) {
        if (!used_y[y]) {
            r = y;
            break;
        }
    }

    vector<int> ids(n);
    iota(ALL(ids), 0);
    sort(ALL(ids), [&](int l, int r) {
        return a[l] > a[r];
    });

    auto dfs = [&](auto &&self, int cur) -> pair<vector<int>, vector<int>> {
        // 左
        vector<int> dpl(n, -inf);

        if (g[cur].first != -1) {
            auto[cdpl, cdpr] = self(self, g[cur].first);

            set<int> st; // (r)
            vector<int> mp(n); // key: r, value: l
            st.insert(inf);
            st.insert(-inf);
            for (auto i : ids) {
                {
                    // max(l) s.t. r < i
                    auto itr = st.upper_bound(i - 1);
                    itr--;
                    if (*itr != -inf) dpl[i] = mp[*itr];
                }

                int l = cdpl[i];
                int r = cdpr[i];
                // 区間 [l, r] を挿入 ... する前に、

                if (l != -inf and r != inf) {
                    // パターン 1. [l, r] を含む区間については消去する
                    while (true) {
                        auto itr = st.upper_bound(r - 1);
                        if (*itr != inf and mp[*itr] <= l) {
                            // cerr << "erase: [" << itr->second << ", " << itr->first << "]" << endl;
                            st.erase(itr);
                        } else {
                            break;
                        }
                    }

                    // パターン 2. [l, r] が含む区間が存在しないなら、挿入する
                    {
                        auto itr = st.upper_bound(r);
                        itr--;
                        if (*itr == -inf or (*itr != r and mp[*itr] < l)) {
                            st.insert(r);
                            mp[r] = l;
                        }
                    }
                }
            }

        } else {
            iota(ALL(dpl), 0);
        }

        // 右
        vector<int> dpr(n, inf);
        if (g[cur].second != -1) {
            auto[cdpl, cdpr] = self(self, g[cur].second);
            set<int> st; // (l)
            vector<int> mp(n);

            st.insert(inf);
            st.insert(-inf);

            for (auto i : ids) {
                {
                    // min(r) s.t. i < l
                    auto itr = st.upper_bound(i);
                    if (*itr != inf) dpr[i] = mp[*itr];
                }

                int l = cdpl[i];
                int r = cdpr[i];
                // 区間 [l, r] を挿入 ... する前に、

                if (l != -inf and r != inf) {
                    // パターン 1. [l, r] を含む区間については消去する
                    while (true) {
                        auto itr = st.upper_bound(l);
                        itr--;
                        if (*itr != -inf and r <= mp[*itr]) {
                            st.erase(itr);
                        } else {
                            break;
                        }
                    }

                    // パターン 2. [l, r] が含む区間が存在しないなら、挿入する
                    {
                        auto itr = st.upper_bound(l - 1);
                        if (*itr == inf or (*itr != l and r < mp[*itr])) {
                            st.insert(l);
                            mp[l] = r;
                        }
                    }
                }
            }


        } else {
            iota(ALL(dpr), 0);
        }

        return {dpl, dpr};
    };

    auto[dpl, dpr] = dfs(dfs, r);
    for (int i = 0; i < n; i++) {
        if (dpl[i] != -inf and dpr[i] != inf) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
