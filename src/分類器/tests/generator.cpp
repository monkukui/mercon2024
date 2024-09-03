#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>
#include "../../common/xrand.h"
#include "constraints.hpp"

const int num_of_type = 5;
std::string case_type[num_of_type] = {"10_random_normal_","11_random_small_","12_random_max_","20_one_","30_full_"};
int num_of_case[num_of_type] = {10,10,10,3,3};
int min_m[num_of_type] = {MIN_M,MIN_M,MAX_M,MIN_M,MIN_M};
int max_m[num_of_type] = {MAX_M,MAX_M,MAX_M,MAX_M,MAX_M};
int min_n[num_of_type] = {MIN_N,MIN_N,MAX_N,MIN_N,MIN_N};
int max_n[num_of_type] = {MAX_N,MAX_N,MAX_N,MAX_N,MAX_N};
char charset[2] = {'o','x'};

XRand Rnd(334);

int main(){
    for(int typenum=0;typenum<num_of_type;typenum++){
        for(int casenum=0;casenum<num_of_case[typenum];casenum++){
            int num = casenum;
            std::ostringstream sout;
            sout << std::setfill('0') << std::setw(2) << num;
            std::string num_string = sout.str();

            std::string file_name=case_type[typenum]+num_string+".in";
            std::ofstream output(file_name);

            int m=Rnd.NextInt(min_m[typenum],max_m[typenum]);
            int n=Rnd.NextInt(min_n[typenum],max_n[typenum]);
            output<<m<<" "<<n<<std::endl;
            std::vector<std::vector<bool>> is_cloud(m,std::vector<bool>(n,false));

            int num_of_cloud = 1;
            int put_cloud = 0;
            int begin_index = 0;
            int last_index = m*n-1;
            switch(typenum){
                case 0:
                case 1:
                case 2:
                    num_of_cloud = Rnd.NextInt(0,m*n);
                    for(int i=0;i<num_of_cloud;i++){
                        put_cloud = Rnd.NextInt(begin_index,last_index);
                        is_cloud[put_cloud/n][put_cloud%n] = true;
                    }
                    break;
                case 3:
                    for(int i=0;i<num_of_cloud;i++){
                        put_cloud = Rnd.NextInt(begin_index,last_index);
                        is_cloud[put_cloud/n][put_cloud%n] = true;
                    }
                    break;
                case 4:
                    for(int i=0;i<m;i++){
                        for(int j=0;j<n;j++){
                            is_cloud[i][j] = true;
                        }
                    }
                    break;
                default:
                    return 1;
                    break;
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(is_cloud[i][j]){
                        output<<charset[0];
                    }else{
                        output<<charset[1];
                    }
                }
                output<<std::endl;
            }

            output.close();
        }
    }
    return 0;
}