#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include <random>
#include "../../../common/xrand.h"
#include "constraints.hpp"
using namespace std;

XRand Rnd(334);
int random_max_NX_testcase_num = 3;
int random_max_N_testcase_num = 3;
int random_max_X_testcase_num = 3;
int random_max_NX_few_larg_A_num = 3;
int random_max_NX_small_A_num = 3;
int random_max_NX_one_big_A_num = 3;
int random_max_NX_just_X_num = 3;
int random_max_NX_just_X_few_pattern_num = 5;
int random_max_NX_all_A_num = 2;
int random_max_NXA_num = 1;
int random_max_NX_all_A_use_same_A_num = 3;

void random_max_NX(int casenum) {
    std::string file_name="10_random_max_NX"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int N = MAX_N, X = MAX_X;
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

void random_max_N(int casenum) {
    std::string file_name="11_random_max_N"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int N = MAX_N;
    int X = Rnd.NextInt(MIN_X, MAX_X);
    output<< N << ' ' << X << std::endl;
    for (int i = 0; i < N; i++) {
        int A = Rnd.NextInt(MIN_A, X);
        output<< A;
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_X(int casenum) {
    std::string file_name="12_random_max_X"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = Rnd.NextInt(MIN_N, MAX_N);
    output<< N << ' ' << X << std::endl;
    for (int i = 0; i < N; i++) {
        int A = Rnd.NextInt(MIN_A, X);
        output<< A;
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_NX_few_larg_A(int casenum) {
    std::string file_name="13_random_max_NX_few_larg_A"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    int large_num = N / 10;
    int random_num = N - large_num;
    output<< N << ' ' << X << std::endl;
    for (int i = 0; i < random_num; i++) {
        int A = Rnd.NextInt(MIN_A, MIN_A + 10);
        output<< A;
        output << ' ';
    }
    for (int i = 0; i < large_num; i++) {
        int A = Rnd.NextInt(X - 10, X);
        output<< A;
        if (i != large_num - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_NX_small_A(int casenum) {
    std::string file_name="14_random_max_NX_small_A"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    output<< N << ' ' << X << std::endl;
    for (int i = 0; i < N; i++) {
        int A = Rnd.NextInt(MIN_A, MIN_A + 10);
        output<< A;
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_NX_one_big_A(int casenum) {
    std::string file_name="15_random_max_NX_one_big_A"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    output<< N << ' ' << X << std::endl;
    for (int i = 0; i < N - 1; i++) {
        int A = Rnd.NextInt(MIN_A, MIN_A + 3);
        output<< A;
        output << ' ';
    }
    int A = Rnd.NextInt(X - 5, X);
    output<< A;
    output << std:: endl;
}

void random_max_NX_just_X(int casenum) {
    std::string file_name="16_random_max_NX_just_X"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    output<< N << ' ' << X << std::endl;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int A = Rnd.NextInt(MIN_A, X);
        if (sum + A >= X) {
            output<< X - sum;
        }
        else {
            output<< A;
            sum += A;
        }
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_NX_just_X_few_pattern(int casenum) {
    std::string file_name="17_random_max_NX_just_X_few_pattern"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    output<< N << ' ' << X << std::endl;
    vector<int> A = {X - 5, 2, 3, X - 7, 1, 6};
    int same_A = Rnd.NextInt(MIN_A + 8, MIN_A + 20);
    while (A.size() != N) {
        A.push_back(same_A);
    }
    std::random_device rd;  // 乱数生成器
    std::mt19937 g(rd());   // メルセンヌ・ツイスター乱数エンジン

    // 配列の要素をシャッフル
    std::shuffle(A.begin(), A.end(), g);

    for (int i = 0; i < N; i++) {
        output<< A.at(i);
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_NX_all_A(int casenum) {
    std::string file_name="18_random_max_NX_all_A"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    output<< N << ' ' << X << std::endl;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        A.push_back(i % X + 1);
    }
    std::random_device rd;  // 乱数生成器
    std::mt19937 g(rd());   // メルセンヌ・ツイスター乱数エンジン

    // 配列の要素をシャッフル
    std::shuffle(A.begin(), A.end(), g);

    for (int i = 0; i < N; i++) {
        output<< A.at(i);
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void max_NXA(int casenum) {
    std::string file_name="19_max_NXA"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int X = MAX_X;
    int N = MAX_N;
    output<< N << ' ' << X << std::endl;

    for (int i = 0; i < N; i++) {
        output<< X;
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

void random_max_NX_all_A_use_same_A(int casenum) {
    std::string file_name="20_random_max_NX_all_A_use_same_A"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int N = MAX_N;
    int X = 10;
    output<< N << ' ' << X << std::endl;
    vector<int> A;
    for (int i = MIN_A; i <= X; ++i) {
        A.push_back(i);
    }
    int same_A = Rnd.NextInt(MIN_A, X);
    while (A.size() != N) {
        A.push_back(same_A);
    }
    std::random_device rd;  // 乱数生成器
    std::mt19937 g(rd());   // メルセンヌ・ツイスター乱数エンジン

    // 配列の要素をシャッフル
    std::shuffle(A.begin(), A.end(), g);

    for (int i = 0; i < N; i++) {
        output<< A.at(i);
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
    for (int i = 0; i < random_max_N_testcase_num; i++) {
        random_max_N(i);
    }
    for (int i = 0; i < random_max_X_testcase_num; i++) {
        random_max_X(i);
    }
    for (int i = 0; i < random_max_NX_few_larg_A_num; i++) {
        random_max_NX_few_larg_A(i);
    }
    for (int i = 0; i < random_max_NX_small_A_num; i++) {
        random_max_NX_small_A(i);
    }
    for (int i = 0; i < random_max_NX_one_big_A_num; i++) {
        random_max_NX_one_big_A(i);
    }
    for (int i = 0; i < random_max_NX_just_X_num; i++) {
        random_max_NX_just_X(i);
    }
    for (int i = 0; i < random_max_NX_just_X_few_pattern_num; i++) {
        random_max_NX_just_X_few_pattern(i);
    }
    for (int i = 0; i < random_max_NX_all_A_num; i++) {
        random_max_NX_all_A(i);
    }
    for (int i = 0; i < random_max_NX_all_A_use_same_A_num; i++) {
        random_max_NX_all_A_use_same_A(i);
    }
    max_NXA(1);
    return 0;
}
