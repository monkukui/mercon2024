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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> x(m - 1);
    vector<int> y(m - 1);
    for (int i = 0; i < m - 1; i++) {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
    }

    // n 個数の中から m 個数選ぶ O(nCm)
    vector<int> p(n, 0);
    for (int i = 0; i < m; i++) p[i] = 1;
    sort(ALL(p));

    do {
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (p[i] == 1) {
                b.push_back(a[i]);
            }
        }
        assert(b.size() == m);
        bool ok = true;
        for (int i = 0; i < m - 1; i++) {
            if (b[x[i]] > b[y[i]]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            for (int i = 0; i < b.size(); i++) {
                cerr << b[i] << " ";
            }
            cerr << endl;
            for (int i = 0; i < m - 1; i++) {
              cerr << b[x[i]] << " " << b[y[i]] << endl;
            }
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(ALL(p)));

    cout << "No" << endl;
    return 0;
}
