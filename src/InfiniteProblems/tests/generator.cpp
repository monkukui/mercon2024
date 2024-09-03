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
//パターン1:K大N大a小p適当
//パターン2:Aが制限ギリギリまで大きい（5ケースもあれば十分）
const int num_of_type = 2;
std::string case_type[num_of_type] = {"10_random_small_","11_random_large_"};
int num_of_case[num_of_type] = {10,10};
long long min_n[num_of_type] = {MIN_N,MAX_N/2};
long long max_n[num_of_type] = {MAX_N,MAX_N};
long long min_k[num_of_type] = {MAX_K/2,MIN_K};
long long max_k[num_of_type] = {MAX_K,MAX_K};
long long min_a[num_of_type] = {MIN_a,MIN_a};
long long max_a[num_of_type] = {10,MAX_a};
//long long min_p[num_of_type] = {1};
//long long max_p[num_of_type] = {10};


XRand Rnd(2010);

int main() {
    for(int typenum=0;typenum<num_of_type;++typenum){
        for(int casenum=0;casenum<num_of_case[typenum];++casenum){
            std::string file_name=case_type[typenum]+std::to_string(casenum)+".in";
            std::ofstream output(file_name);
            long long N=Rnd.NextLong(min_n[typenum],max_n[typenum]);
            long long K=Rnd.NextLong(min_k[typenum],max_k[typenum]);
            output<<N<<" "<<K<<std::endl;
            for(int i=1;i<=N;i++){
                long long A=Rnd.NextLong(min_a[typenum],max_a[typenum]);
                output<<A;
                if(i==N) output<<std::endl;
                else output<<" ";
            }
            if(typenum==0){
                long long r=Rnd.NextLong(0,1);
                if(r==0){
                    for(int i=2;i<=N;i++){
                        long long P=Rnd.NextLong(1,i-1);
                        output<<P;
                        if(i==N) output<<std::endl;
                        else output<<" ";
                    }
                }
                if(r==1){
                    for(int i=2;i<=N;i++){
                        long long P=Rnd.NextLong(1,i-1);
                        output<<P;
                        if(i==N) output<<std::endl;
                        else output<<" ";
                    }
                }
            output.close();
            }
            if(typenum==1){
                for(int i=2;i<=N;i++){
                    long long P=Rnd.NextLong(1,i-1);
                    output<<P;
                    if(i==N) output<<endl;
                    else output<<" ";
                }
            }
        }
    }
    return 0;
}
