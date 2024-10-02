#include <iostream>
#include <vector>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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

using lint = long long int;
using i128 = __int128;
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

using namespace std;

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
    template <typename RandomAccessIterator>
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
        for (; ; ) {
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
        for (; ; ) {
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

template <typename RandomAccessIterator>
void XRand::Shuffle(RandomAccessIterator first, RandomAccessIterator last) {
    for (RandomAccessIterator iter = first; iter != last; ++iter) {
        std::iter_swap(first + NextUInt(iter - first + 1), iter);
    }
}

#endif  // #ifndef XRAND_H_

XRand rnd(285);

int main() {
    lint n, m; cin >> n >> m;
    vector<lint> x(n), d(n), c(n);
    map<pair<int, int>, lint> mp;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> d[i] >> c[i];
        x[i]--;
        d[i]--;
        mp[make_pair(x[i], d[i])] = c[i];
    }

    vector<vector<lint>> dp(m + 2, vector<lint>(m + 2, -1));
    dp[0][0] = mp[make_pair(0, 0)];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == -1) continue;
            chmax(dp[i + 1][j + 1], dp[i][j] + mp[make_pair(i + 1, j + 1)]);
            chmax(dp[i][j + 1], dp[i][j] + mp[make_pair(i, j + 1)]);
            chmax(dp[max(0, i - 1)][j + 1], dp[i][j] + mp[make_pair(max(0, i - 1), j + 1)]);
        }
    }

    lint ans = 0;
    for (int i = 0; i <= m + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            chmax(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}

