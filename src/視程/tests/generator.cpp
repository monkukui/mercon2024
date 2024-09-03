#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <random>
#include <set>
#include "../../common/xrand.h"
#include "constraints.hpp"
using namespace std;

std::random_device seed;
XRand rand(905);

const int min_n_[] = {MIN_N,100,MAX_N};
const int max_n_[] = {20,500,MAX_N};

void random_case(ostream &ofs, int case_size){
  const int min_n = min_n_[case_size];
  const int max_n = max_n_[case_size];
  int N = rand.NextInt(min_n,max_n);
  ofs << N << endl;
  for(int i = 0; i < N; ++i){
    ofs << rand.NextInt(MIN_H,MAX_H) << (i+1 < N ? ' ' : '\n');
  }
}

void generate(ostream &ofs, const string &case_name){
  int case_size = case_name[1] - '0';
  if(case_name[0] == '1'){
    random_case(ofs, case_size);
  }
}

int main(){
  
  vector<string> case_name = {
    "10_random_small_","11_random_large_","12_random_max_",
  };


  vector<int> case_num = {
    10,10,10
  };


  for (size_t i = 0; i < case_num.size(); i++) {
    for (int j = 0; j < case_num[i]; j++) {
      char id[10];
      sprintf(id, "%02d", j);
      string name = case_name[i] + id + ".in";
      ofstream ofs(name);
      generate(ofs, case_name[i]);
      ofs.close();
    }
  }
  return 0;
}

