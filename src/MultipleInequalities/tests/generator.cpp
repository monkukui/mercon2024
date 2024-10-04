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
int num_of_case[num_of_type] = {100, 20};
int min_n[num_of_type] = {10, MAX_N};
int max_n[num_of_type] = {30, MAX_N};

void generate_random(int n, int m, string file_name) {
    std::ofstream output(file_name);
    output << n << " " << m << endl;
    // 長さ n の順列を生成
    vector<int> T(n);
    iota(T.begin(), T.end(), 0);
    rnd.Shuffle(T.begin(), T.end());
    vector<int> P(m);
    iota(P.begin(), P.end(), 0);
    rnd.Shuffle(P.begin(), P.end());

    for (int i = 0; i < T.size(); i++) {
        if (i + 1 == T.size()) output << T[i] + 1 << endl;
        else output << T[i] + 1 << " ";
    }

    for (int i = 0; i < P.size(); i++) {
        if (i + 1 == P.size()) output << P[i] + 1 << endl;
        else output << P[i] + 1 << " ";
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
