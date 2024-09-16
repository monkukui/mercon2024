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

const int num_of_type = 2;
std::string case_type[num_of_type] = {"10_random_small","11_random_large"};
int num_of_case[num_of_type] = {15,15};
int min_n[num_of_type] = {1,MAX_N};
int max_n[num_of_type] = {100,MAX_N};

XRand Rnd(283);

int main() {
    for(int typenum=0;typenum<num_of_type;++typenum){
        for(int casenum=0;casenum<num_of_case[typenum];++casenum){
            std::string file_name=case_type[typenum]+std::to_string(casenum)+".in";
            std::ofstream output(file_name);

            int n=Rnd.NextInt(min_n[typenum],max_n[typenum]);
            int k = Rnd.NexInt(1, n);
            output<<n<<" "<<k<<std::endl;

            // generate tree
            std::vector<int> p(n);
            for(int i=1;i<n;++i){
                p[i]=Rnd.NextInt(0,i-1);
            }
            std::random_shuffle(p.begin(),p.end());
            for(int i=1;i<n;++i){
                output<<p[i]+1<<" "<<i+1<<std::endl;
            }

            // generate permutation
            std::vector<int> perm(n);
            for(int i=0;i<n;++i){
                perm[i]=i;
            }
            std::random_shuffle(perm.begin(),perm.end());
            for(int i=0;i<n;++i){
                output<<perm[i]+1<<" ";
            }

            output.close();
        }
    }
    return 0;
}
