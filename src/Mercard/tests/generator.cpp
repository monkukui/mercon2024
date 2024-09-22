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

XRand Rnd(334);
int random_max_NX_testcase_num = 5;

void random_max_NX(int casenum) {
    std::string file_name="10_random_max_NX"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int N = 300, X = 300;
    output<< N << ' ' << X << std::endl;
    for (int i = 0; i < N; i++) {
        int A =Rnd.NextInt(MIN_A, X);
        output<< A;
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

int main() {
    for (int i = 0; i < random_max_NX_testcase_num; i++) {
        random_max_NX(i);
    }
    return 0;
}
