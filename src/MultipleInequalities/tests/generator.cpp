#include <iostream>
#include <random>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include "../../../common/xrand.h"
#include "constraints.hpp"

using namespace std;

XRand rnd(283);

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


const int num_of_type = 2;
std::string case_type[num_of_type] = {"10_random_small","11_random_large"};
int num_of_case[num_of_type] = {100,20};
int min_n[num_of_type] = {1,MAX_N};
int max_n[num_of_type] = {20,MAX_N};

void generate_random(int n, int m, string file_name) {
    std::ofstream output(file_name);
    output << n << " " << m << endl;
    // 長さ n の順列を生成
    vector<int> T(n);
    iota(T.begin(), T.end(), 0);
    rnd.Shuffle(T.begin(), T.end());
    // 長さ m の部分列を取得
    // (0, ..., n - 1) をシャッフルして、前から m 個を対象の添え字列としてソート
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    rnd.Shuffle(I.begin(), I.end());
    vector<int> II(m);
    for (int i = 0; i < m; i++) {
        II[i] = I[i];
    }
    sort(II.begin(), II.end());
    vector<int> P(m);
    for (int i = 0; i < m; i++) {
        P[i] = T[II[i]];
    }

    for (int i = 0; i < T.size(); i++) {
        if (i + 1 == T.size()) output << T[i] + 1 << endl;
        else output << T[i] + 1 << " ";
    }

    auto p = cartesian_tree(P);

    vector<pair<int, int>> g(m, {-1, -1});
    int r = min_element(P.begin(), P.end()) - P.begin();
    for (int i = 0; i < m; i++) {
        if (p[i] < 0) continue;
        if (i < p[i]) {
            g[p[i]].first = i;
        }
        if (i > p[i]) {
            g[p[i]].second = i;
        }
    }
    vector<pair<int, int>> xy;
    for (int i = 0; i < m; i++) {
        if (g[i].first != -1) {
            xy.push_back({i, g[i].first});
        }
        if (g[i].second != -1) {
            xy.push_back({i, g[i].second});
        }
    }
    assert(xy.size() == m - 1);
    for (int i = 0; i < m - 1; i++) {
        output << xy[i].first + 1 << " " << xy[i].second + 1 << endl;
    }

    return;
}

int main() {
    for(int typenum=0;typenum<num_of_type;++typenum) {
        for (int casenum = 0; casenum < num_of_case[typenum]; ++casenum) {
            std::string file_name = case_type[typenum] + std::to_string(casenum) + ".in";
            int n = rnd.NextInt(min_n[typenum], max_n[typenum]);
            int m = rnd.NextInt(1, n);
            generate_random(n, m, file_name);
        }
    }
    return 0;
}
