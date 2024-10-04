#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include <random>
#include <set>
#include "../../common/xrand.h"
#define ll long long
using namespace std;

XRand Rnd(334);

void random_small_N(int casenum) {
    std::string file_name="01_random_small_"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int N = Rnd.NextInt(2, 8), P = Rnd.NextInt(300, 1000);
    output<< N << ' ' << P << std::endl;
    vector<string> S = {"sold_out", "on_sale"};
    for (ll i = 0; i < N; ++i) {
        int C = Rnd.NextInt(300, 1000);
        int si = Rnd.NextInt(0, 1);
        output << C << ' ' << S.at(si) << endl;
    }
}

int main() {
    for (int i = 0; i < 5; ++i) {
        random_small_N(i);
    }
    return 0;
}
