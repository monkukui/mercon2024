#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <utility>
#include "../../common/xrand.h"
#include "constraints.hpp"

const int num_of_type = 5;
std::string case_type[num_of_type] = {"k1_case", "k2_case", "k_over3_case", "n_small_case", "n_large_case"};
int num_of_case[num_of_type] = {k1_case, k2_case, k_over3_case, n_small_case, n_large_case};
int min_n[num_of_type] = {MIN_N,     1,     2,   MIN_N, MAX_N-10};
int max_n[num_of_type] = {MAX_N, MAX_N, MAX_N, MIN_N+1,    MAX_N};
int min_k[num_of_type] = {    1,     2,     3,       1,        1};
int max_k[num_of_type] = {    1,     2,     3,   MAX_K,    MAX_K};

XRand Rnd(2784);

int main() {
    for(int typenum = 0; typenum < num_of_type; ++typenum){
        for(int casenum = 0; casenum < num_of_case[typenum]; ++casenum){
            std::string file_name = case_type[typenum] + std::to_string(casenum) + ".in";
            std::ofstream output(file_name);


            int n = Rnd.NextInt(min_n[typenum], max_n[typenum]);
            output << n << ' ';

            int this_max_k = max_k[typenum];
            if(n < 31) this_max_k = std::min(this_max_k, (1<<n));
            int k = Rnd.NextInt(min_k[typenum], this_max_k);
            output << k << std::endl;

            output.close();
        }
    }
    return 0;
}
