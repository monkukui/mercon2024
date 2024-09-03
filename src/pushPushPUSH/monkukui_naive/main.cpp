// 愚直解
// dp[bit][赤色の頂点がどこか] := true/false
// 遷移：bit が立ってる頂点を一つ選んで、隣接頂点に移動
// bfs 的にやる
// O*(2^n)
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

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int k; cin >> k;
    vector<int> v(k);
    int init_bit = 0;
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        v[i]--;
        init_bit = init_bit | (1 << v[i]);
    }
    int s, t; cin >> s >> t;
    s--;
    t--;
    vector<vector<bool>> dp((1 << n), vector<bool>(n, false));
    queue<pair<int, int>> que;
    dp[init_bit][s] = true;
    que.push({init_bit, s});
    while (!que.empty()) {
        auto [bit, cur] = que.front();
        que.pop();

        // どのブロックを動かすか
        for (int a = 0; a < n; a++) {
            if (!(bit & (1 << a))) continue;
            // a を どこに動かすか
            for (auto b : g[a]) {
                // 動かす先にブロックがあるなら、だめ
                if (bit & (1 << b)) continue;
                int nxt = (a == cur) ? b : cur;
                int nbit = bit;
                nbit |= (1 << b);
                nbit -= (1 << a);
                if (dp[nbit][nxt]) continue;
                dp[nbit][nxt] = true;
                que.push({nbit, nxt});
            }
        }
    }

    for (int bit = 0; bit < (1 << n); bit++) {
        if (dp[bit][t]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
