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

const int num_of_type = 4;
std::string case_type[num_of_type] = {"10_random_small","11_random_large","20_all_a","21_all_n"};
int num_of_case[num_of_type] = {10,10,5,5};
int min_n[num_of_type] = {1,MAX_N,1,1};
int max_n[num_of_type] = {100,MAX_N,MAX_N,MAX_N};
char charset[2] = {'A','N'};

XRand Rnd(334);

int main() {
    for(int typenum=0;typenum<num_of_type;++typenum){
        for(int casenum=0;casenum<num_of_case[typenum];++casenum){
            std::string file_name=case_type[typenum]+std::to_string(casenum)+".in";
            std::ofstream output(file_name);


            int n=Rnd.NextInt(min_n[typenum],max_n[typenum]);
            output<<n<<std::endl;

            switch(typenum) {
                case 0:
                case 1:
                    for(int i = 0; i < n; ++i) {
                        output<<charset[Rnd.NextInt(0,1)];
                    }
                    output<<std::endl;
                break;

                case 2:
                    for(int i = 0; i < n; ++i) {
                        output<<charset[0];
                    }
                    output<<std::endl;
                break;

                case 3:
                    for(int i = 0; i < n; ++i) {
                        output<<charset[1];
                    }
                    output<<std::endl;
                break;
            }

            output.close();
        }
    }
    return 0;
}
