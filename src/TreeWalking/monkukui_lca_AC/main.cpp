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

using namespace std;

using lint = long long int;
using i128 = __int128;
const long long int INF = numeric_limits<long long int>::max() / 4;
const int inf = 1e9;
const long long int MOD = 998244353;
const double MATH_PI = 3.1415926535897932;

template<typename T1, typename T2>
inline void chmin(T1 &a, const T2 &b) { if (a > b) a = b; }

template<typename T1, typename T2>
inline void chmax(T1 &a, const T2 &b) { if (a < b) a = b; }

#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i, n) for(int i=0;i<(int)(n);i++)

#define SUM(v) accumulate(ALL(v), 0LL)
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))

#ifdef LOCAL

ostream& operator<<(ostream& os, __int128_t x) {
    if (x < 0) {
        os << "-";
        x *= -1;
    }
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}
ostream& operator<<(ostream& os, __uint128_t x) {
    if (x == 0) {
        return os << "0";
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p);
template <class T> ostream& operator<<(ostream& os, const vector<T>& v);
template <class T> ostream& operator<<(ostream& os, const deque<T>& v);
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a);
template <class T> ostream& operator<<(ostream& os, const set<T>& s);
template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& m);

template <typename T, typename Container>
ostream &operator<<(ostream &os,
                         const priority_queue<T, Container> &pq);

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const deque<T>& v) {
    os << "[";
    bool f = false;
    for (auto d : v) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}
template <class T, size_t N>
ostream& operator<<(ostream& os, const array<T, N>& a) {
    os << "[";
    bool f = false;
    for (auto d : a) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "]";
}

template <class T> ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{";
    bool f = false;
    for (auto d : s) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "}";
}
template <class T> ostream& operator<<(ostream& os, const multiset<T>& s) {
    os << "{";
    bool f = false;
    for (auto d : s) {
        if (f) os << ", ";
        f = true;
        os << d;
    }
    return os << "}";
}

template <class T, class U>
ostream& operator<<(ostream& os, const map<T, U>& s) {
    os << "{";
    bool f = false;
    for (auto p : s) {
        if (f) os << ", ";
        f = true;
        os << p.first << ": " << p.second;
    }
    return os << "}";
}

template <typename T, typename Container>
ostream &operator<<(ostream &os,
                         const priority_queue<T, Container> &pq) {
  priority_queue<T, Container> temp =
      pq;

  os << "[";
  bool f = false;
  while (!temp.empty()) {
    if (f) os << ", ";
    f = true;
    os << temp.top();
    temp.pop();
  }
  os << "]";

  return os;
}

struct PrettyOS {
    ostream& os;
    bool first;

    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

namespace monkukui {
    namespace output {
        void yesno(bool f) {
            if (f) cout << "Yes" << endl;
            else cout << "No" << endl;
        }

        template<class T>
        void vec(vector <T> a) {
            for (int i = 0; i < (int) a.size(); i++) {
                if (i + 1 == (int) a.size()) cout << a[i] << endl;
                else cout << a[i] << " ";
            }
        }

        template<class T>
        void grid(vector <vector<T>> g) {
            int h = g.size();
            int w = g[0].size();
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (j + 1 == w) cout << g[i][j] << endl;
                    else cout << g[i][j] << " ";
                }
            }
        }
    }

    namespace input {
        template<class T>
        vector <T> vec(int n) {
            vector <T> a(n);
            for (int i = 0; i < n; i++) cin >> a[i];
            return a;
        }

        vector <vector<int>> unweighted_graph(int n, int m, bool directed = false) {
            vector <vector<int>> g(n);
            for (int i = 0; i < m; i++) {
                int a, b;
                cin >> a >> b;
                a--;
                b--;
                g[a].emplace_back(b);
                if (!directed) g[b].emplace_back(a);
            }
            return g;
        }

        template<class T>
        vector <vector<pair < int, T>>>

        weighted_graph(int n, int m, bool directed = false) {
            vector <vector<int>> g(n);
            for (int i = 0; i < m; i++) {
                int a, b;
                cin >> a >> b;
                T c;
                cin >> c;
                a--;
                b--;
                g[a].emplace_back({b, c});
                if (!directed) g[b].emplace_back({a, c});
            }
            return g;
        }

        template<class T>
        vector <vector<T>> grid(int h, int w) {
            vector <vector<T>> ret(h, vector<T>(w));
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    cin >> ret[i][j];
                }
            }
            return ret;
        }
    }
}

struct Timer {
    struct timeval start, cur;
    double limit;

    Timer() : limit(0) { gettimeofday(&start, NULL); }

    Timer(double l) : limit(l) { gettimeofday(&start, NULL); }

    bool isLimit() { return curTime() > limit; }

    double curTime() {
        gettimeofday(&cur, NULL);
        return (cur.tv_sec - start.tv_sec) + (cur.tv_usec - start.tv_usec) / 1e6;
    }
};

// xrand.h - An implementation of xorshift random number generator.
// See the description of class XRand for its usage.
// Version 0.2

// Copyright (c) 2013  Kazuhiro Hosaka (hos@hos.ac)
//
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
//    1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
//
//    2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
//
//    3. This notice may not be removed or altered from any source
//    distribution.

#ifndef XRAND_H_
#define XRAND_H_

#include <assert.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <algorithm>

#ifndef UINT32_MAX
#define UINT32_MAX (4294967295U)
#endif

#ifndef UINT64_MAX
#define UINT64_MAX (18446744073709551615ULL)
#endif

#define rand           _DO_NOT_USE_RAND_
#define srand          _DO_NOT_USE_SRAND_
#define random_shuffle _DO_NOT_USE_RANDOM_SHUFFLE_

class XRand {
public:
    // Initializes with the given seed.
    explicit XRand(uint64_t seed = 0);

    void Reset(uint64_t seed);

    // Generates the next random number, changing the state of the generator.
    // NextULong() calls NextUInt() twice.
    uint32_t NextUInt();

    uint64_t NextULong();

    // Returns an integer, almost uniformly distributed in [0, m).
    // It must hold that m != 0.
    // Calls NextUInt() once for UInt and twice for ULong.
    uint32_t NextUInt(uint32_t m);

    uint64_t NextULong(uint64_t m);

    // Returns an integer, almost uniformly distributed in [a, b].
    // It must hold that a <= b.
    // Calls NextUInt() once for Int and twice for Long.
    int32_t NextInt(int32_t a, int32_t b);

    int64_t NextLong(int64_t a, int64_t b);

    // The unbiased version of the methods above.
    // The number of calls to NextUInt() is not deterministic.
    // The expected number of that is at most two for (U)Int and four for (U)Long.
    uint32_t NextUIntUnbiased(uint32_t m);

    uint64_t NextULongUnbiased(uint64_t m);

    int32_t NextIntUnbiased(int32_t a, int32_t b);

    int64_t NextLongUnbiased(int64_t a, int64_t b);

    // Returns a double, uniformly distributed in [0.0, 1.0).
    // Calls NextUInt() twice.
    double NextDouble();

    // Returns a double, normally distributed with expectation 0 and variance 1.
    // Calls NextUInt() four times.
    double NextGaussian();

    // Shuffles the interval [first, last).
    // Calls NextUInt() (last - first) times.
    template<typename RandomAccessIterator>
    void Shuffle(RandomAccessIterator first, RandomAccessIterator last);

private:
    uint32_t x_, y_, z_, w_;
};

XRand::XRand(uint64_t seed) {
    Reset(seed);
}

void XRand::Reset(uint64_t seed) {
    x_ = 314159265;
    y_ = 358979323;
    z_ = 846264338 ^ (65535 * static_cast<uint32_t>(seed >> 32));
    w_ = 327950288 ^ (65535 * static_cast<uint32_t>(seed));
}

uint32_t XRand::NextUInt() {
    const uint32_t t = x_ ^ x_ << 11;
    x_ = y_;
    y_ = z_;
    z_ = w_;
    return w_ = w_ ^ w_ >> 19 ^ t ^ t >> 8;
}

uint64_t XRand::NextULong() {
    const uint64_t high = NextUInt();
    const uint64_t low = NextUInt();
    return high << 32 | low;
}

uint32_t XRand::NextUInt(uint32_t m) {
    assert(m != 0);
    return NextUInt() % m;
}

uint64_t XRand::NextULong(uint64_t m) {
    assert(m != 0);
    return NextULong() % m;
}

int32_t XRand::NextInt(int32_t a, int32_t b) {
    assert(a <= b);
    return a + NextUInt(b - a + 1);
}

int64_t XRand::NextLong(int64_t a, int64_t b) {
    assert(a <= b);
    return a + NextULong(b - a + 1);
}

uint32_t XRand::NextUIntUnbiased(uint32_t m) {
    assert(m != 0);
    if (m & (m - 1)) {
        const uint32_t limit = UINT32_MAX / m * m;
        for (;;) {
            const uint32_t value = NextUInt();
            if (value < limit) {
                return value % m;
            }
        }
    } else {
        return NextUInt() & (m - 1);
    }
}

uint64_t XRand::NextULongUnbiased(uint64_t m) {
    assert(m != 0);
    if (m & (m - 1)) {
        const uint64_t limit = UINT64_MAX / m * m;
        for (;;) {
            const uint64_t value = NextULong();
            if (value < limit) {
                return value % m;
            }
        }
    } else {
        return NextULong() & (m - 1);
    }
}

int32_t XRand::NextIntUnbiased(int32_t a, int32_t b) {
    assert(a <= b);
    return a + NextUIntUnbiased(b - a + 1);
}

int64_t XRand::NextLongUnbiased(int64_t a, int64_t b) {
    assert(a <= b);
    return a + NextULongUnbiased(b - a + 1);
}

double XRand::NextDouble() {
    static const uint64_t kNumValues = 1LL << 53;
    return static_cast<double>(NextULong() & (kNumValues - 1)) / kNumValues;
}

double XRand::NextGaussian() {
    static const double kPi = acos(-1.0);
    const double value1 = NextDouble();
    const double value2 = NextDouble();
    return sqrt(-2.0 * log1p(-value1)) * cos(2.0 * kPi * value2);
}

template<typename RandomAccessIterator>
void XRand::Shuffle(RandomAccessIterator first, RandomAccessIterator last) {
    for (RandomAccessIterator iter = first; iter != last; ++iter) {
        std::iter_swap(first + NextUInt(iter - first + 1), iter);
    }
}

#endif  // #ifndef XRAND_H_

struct LowestCommonAncestor {
    const int LOG;
    vector<int> dep;
    const vector<vector<int>> &g;
    vector<vector<int>> table;

    LowestCommonAncestor(const vector<vector<int>> &g) : g(g), dep(g.size()), LOG(32 - __builtin_clz(g.size())) {
        table.assign(LOG, vector<int>(g.size(), -1));
    }

    void dfs(int idx, int par, int d) {
        table[0][idx] = par;
        dep[idx] = d;
        for (auto &to : g[idx]) {
            if (to != par) dfs(to, idx, d + 1);
        }
    }

    void build() {
        dfs(0, -1, 0);
        for (int k = 0; k + 1 < LOG; k++) {
            for (int i = 0; i < table[k].size(); i++) {
                if (table[k][i] == -1) table[k + 1][i] = -1;
                else table[k + 1][i] = table[k][table[k][i]];
            }
        }
    }

    // lca(u, v) を返す
    int query(int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--) {
            if (((dep[v] - dep[u]) >> i) & 1) v = table[i][v];
        }
        if (u == v) return u;
        for (int i = LOG - 1; i >= 0; i--) {
            if (table[i][u] != table[i][v]) {
                u = table[i][u];
                v = table[i][v];
            }
        }
        assert(table[0][u] != -1);
        return table[0][u];
    }

    // u の深さを返す
    int depth(int u) {
        return dep[u];
    }

    // a, b の距離を返す
    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[query(a, b)];
    }
};

int main() {
    int n, k; cin >> n >> k;
    vector<vector<int>> graph(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i ++) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> height(n, -1);
    {
        queue<int> que;
        vector<bool> used(n, false);
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 and i != 0) {
                que.push(i);
                height[i] = 1;
                used[i] = true;
            }
        }
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int u: graph[v]) {
                if (used[u]) continue;
                height[u] = max(height[u], height[v] + 1);
                deg[u]--;
                if (deg[u] == 1 and u != 0) {
                    used[u] = true;
                    que.push(u);
                }
            }
        }
    }

    if (n == 1) height[0] = 1;


    if (height[0] < k) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> heightToNode(n + 1);
    for (int i = 0; i < n; i++) {
        heightToNode[height[i]].emplace_back(i);
    }


    LowestCommonAncestor lca(graph);
    cerr << "befour build" << endl;
    lca.build();
    cerr << "after build" << endl;

    set<pair<int, int>> candidates;
    // height[v] >= k ならば、v が候補
    for (int i = 0; i < n; i++) {
        if (height[i] >= k) {
            candidates.emplace(x[i], i);
        }
    }

    int cur = 0;
    vector<bool> used(n, false);
    vector<int> ans;
    while (k > 0) {
        // candidates から頂点を取り出す
        int val, nxt;
        while (true) {
            tie(val, nxt) = *candidates.begin();
            candidates.erase({val, nxt});
            if (lca.query(cur, nxt) != cur) continue;
            break;
        }

        ans.emplace_back(val);
        used[nxt] = true;
        cur = nxt;
        k--;

        // k を候補に追加
        for (auto node : heightToNode[k]) {
            candidates.emplace(x[node], node);
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        if (i == (int)ans.size() - 1) cout << ans[i] << endl;
        else cout << ans[i] << " ";
    }
    return 0;
}
