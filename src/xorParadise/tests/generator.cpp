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

const int min_k_[] = {MIN_K, MAX_K};
const int max_k_[] = {MAX_K, MAX_K};

void random_case(ostream &ofs, int case_size){
  const int min_k = min_k_[case_size];
  const int max_k = max_k_[case_size];
  int K = rand.NextLong(min_k,max_k);
  ofs << K << endl;
  vector<int> N(K);
  for(int i = 0; i < K; ++i) {
    N[i] = rand.NextLong(MIN_N,MAX_N);
    ofs << N[i] << (i+1 < K ? ' ' : '\n');
  }
  for(int i = 0; i < K; ++i){
    for (int j = 0; j < N[i]; ++j){
      ofs << rand.NextLong(MIN_A,MAX_A) << (j+1 < N[i] ? ' ' : '\n');
    }
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
    "10_random_small_","11_random_large_",
  };


  vector<int> case_num = {
    10,10
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
