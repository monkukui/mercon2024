#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include "../../common/xrand.h"
#include "constraints.hpp"
using namespace std;
using lint = long long int;

const int num_of_type = 2;
string case_type[7] = {"10_random_small_", "11_random_large_", "20_all_same_", "30_challenge_", "40_challenge_", "50_challenge_", "12_all_max_"};
int num_of_case[7] = {10, 10, 9, 10, 10, 10, 10};
int min_n[7] = {2, 1000, 1000, 1000, 1000, 1000, MAX_N};
int max_n[7] = {50, MAX_N, MAX_N, MAX_N, MAX_N, MAX_N, MAX_N};

XRand Rnd(2525);

int main() {
    for (int i = 0; i < 7; i++) {
        if (i == 0 or i == 1 or i == 6) {
            for (int j = 0; j < num_of_case[i]; j++) {
                string file_name = case_type[i] + to_string(j) + ".in";
                ofstream output(file_name);

                int n = Rnd.NextInt(min_n[i], max_n[i]);
                output << n << endl;
                for (int k = 0; k < n; k++) {
                    int a = Rnd.NextInt(MIN_A, MAX_A);
                    output << a;
                    if (k < n-1) output << " ";
                }
                output << endl;
                output.close();
            }
        }
        else if (i == 2) {
            for (int j = 0; j < num_of_case[i]; j++) {
                string file_name = case_type[i] + to_string(j+1) + ".in";
                ofstream output(file_name);

                int n = Rnd.NextInt(min_n[i], max_n[i]);
                output << n << endl;
                for (int k = 0; k < n; k++) {
                    int a = j+1;
                    output << a;
                    if (k < n-1) output << " ";
                }
                output << endl;
                output.close();
            }
        }
        else if (i == 3) {
            for (int j = 0; j < num_of_case[i]; j++) {
                string file_name = case_type[i] + to_string(j) + ".in";
                ofstream output(file_name);

                int n = Rnd.NextInt(min_n[i], max_n[i]);
                output << n << endl;
                for (int k = 0; k < n; k++) {
                    int a = Rnd.NextInt(1, 4);
                    a *= 2;
                    output << a;
                    if (k < n-1) output << " ";
                }
                output << endl;
                output.close();
            }
        }
        else if (i == 4) {
            for (int j = 0; j < num_of_case[i]; j++) {
                string file_name = case_type[i] + to_string(j) + ".in";
                ofstream output(file_name);

                int n = Rnd.NextInt(min_n[i], max_n[i]);
                output << n << endl;
                for (int k = 0; k < n; k++) {
                    int a = Rnd.NextInt(1, 3);
                    a *= 3;
                    output << a;
                    if (k < n-1) output << " ";
                }
                output << endl;
                output.close();
            }
        }
        else if (i == 5) {
            for (int j = 0; j < num_of_case[i]; j++) {
                string file_name = case_type[i] + to_string(j) + ".in";
                ofstream output(file_name);

                int n = Rnd.NextInt(min_n[i], max_n[i]);
                output << n << endl;
                for (int k = 0; k < n; k++) {
                    int a = Rnd.NextInt(1, 3);
                    if (a == 2) a = 5;
                    else if (a == 3) a = 7;
                    output << a;
                    if (k < n-1) output << " ";
                }
                output << endl;
                output.close();
            }
        }
    }
}