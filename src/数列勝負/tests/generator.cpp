#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include "../../common/xrand.h"
#include "constraints.hpp"

using namespace std;

const int num_of_type = 7;
const int num_of_size = 3;
std::string case_type[num_of_type] = {"10_random_", "20_near_", "30_same_", "40_sorted_0mod3_", "50_sorted_1mod3_", "60_sorted_2mod3_", "70_permutation_"};
std::string case_size[num_of_size] = {"mini_", "small_", "large_"};
int num_of_case[num_of_type] = {5, 4, 1, 2, 2, 2, 5}; // 合計63ケース
int min_n[num_of_size] = {MIN_N, MIN_N, MIN_N};
int max_n[num_of_size] = {5, 20, MAX_N};
int min_v[num_of_type] = {MIN_V, MIN_V, MIN_V, MIN_V, MIN_V, MIN_V, MIN_V};
int max_v[num_of_type] = {MAX_V, MIN_V+10, MIN_V, MAX_V, MAX_V, MAX_V, MAX_V};

XRand rnd(334);

int main() {
    for (int typenum = 0; typenum < num_of_type; typenum++) {
        for (int sizenum = 0; sizenum < num_of_size; sizenum++) {
            for (int casenum = 0; casenum < num_of_case[typenum]; casenum++) {
                std::string file_name = case_type[typenum] + case_size[sizenum] + std::to_string(casenum) + ".in";
                file_name[1] = sizenum+'0';
                std::ofstream output(file_name);

                int n = rnd.NextInt(min_n[sizenum], max_n[sizenum]);
                if (3 <= typenum && typenum <= 5) {
                    n = min_n[sizenum];
                    n += (typenum-n)%3;
                    n += rnd.NextInt(0, (max_n[sizenum]-n)/3);
                }
                output << n << endl;
                vector<int> a(n),b(n);
                if (typenum <= 2) {
                    for (int i = 0; i < n; i++) {
                        a[i] = rnd.NextInt(min_v[typenum],max_v[typenum]);
                    }
                    for (int i = 0; i < n; i++) {
                        b[i] = rnd.NextInt(min_v[typenum],max_v[typenum]);
                    }
                }
                else {
                    vector<int> ab(2*n);
                    iota(ab.begin(), ab.end(), 1);
                    if (typenum == 6) {
                        rnd.Shuffle(ab.begin(), ab.end());
                    }
                    for (int i = 0; i < n; i++) {
                        a[i] = ab[i];
                    }
                    for (int i = 0; i < n; i++) {
                        b[i] = ab[n+i];
                    }
                    reverse(b.begin(), b.end());
                }
                for (int i = 0; i < n; i++) {
                    if (i + 1 == n) output << a[i] << endl;
                    else output << a[i] << " ";
                }
                for (int i = 0; i < n; i++) {
                    if (i + 1 == n) output << b[i] << endl;
                    else output << b[i] << " ";
                }
                output.close();
            }
        }
    }
    return 0;
}
