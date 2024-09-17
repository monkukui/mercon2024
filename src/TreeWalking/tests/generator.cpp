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

const int num_of_type = 3;
std::string case_type[num_of_type] = {"10_random_small","11_random_large", "20_random_path_large"};
int num_of_case[num_of_type] = {10,10, 10};
int min_n[num_of_type] = {1,MAX_N, MAX_N / 2};
int max_n[num_of_type] = {100,MAX_N, MAX_N / 2};

XRand Rnd(283);

int main() {
    for(int typenum=0;typenum<num_of_type;++typenum){
        for(int casenum=0;casenum<num_of_case[typenum];++casenum){
            std::string file_name=case_type[typenum]+std::to_string(casenum)+".in";
            std::ofstream output(file_name);

            int n=Rnd.NextInt(min_n[typenum],max_n[typenum]);

            // generate tree
            std::vector<int> p(n);
            if (typenum <= 1) {
                for (int i = 1; i < n; ++i) {
                    p[i] = Rnd.NextInt(0, i - 1);
                }
            } else {
                for (int i = 1; i < n / 2; i++) {
                    p[i] = i - 1;
                }
                for (int i = n / 2; i < n; i++) {
                    p[i] = Rnd.NextInt(0, i - 1);
                }
            }

            vector<vector<int>> graph(n);
            for (int i = 0; i < n; i++) {
                graph[p[i]].push_back(i);
                graph[i].push_back(p[i]);
            }

            vector<int> height(n, -1);
            auto efs = [&](auto &&f, int v, int p) -> void {
                height[v] = 1;
                for (int u : graph[v]) {
                    if (u == p) continue;
                    f(f, u, v);
                    height[v] = max(height[v], height[u] + 1);
                }
            };
            efs(efs, 0, -1);

            int k = Rnd.NextInt(1, height[0] + 10);
            if (typenum >= 2) {
                k = height[0] / 2;
            }

            output<<n<<" "<<k<<std::endl;

            for(int i=1;i<n;++i){
                output<<p[i]+1<<" "<<i+1<<endl;
            }

            // generate permutation
            std::vector<int> perm(n);
            for(int i=0;i<n;++i){
                perm[i]=i;
            }
            // Rnd.Shuffle(perm.begin(),perm.end());
            for(int i=0;i<n;++i){
                output<<perm[i]+1<<" ";
            }

            output.close();
        }
    }
    return 0;
}
