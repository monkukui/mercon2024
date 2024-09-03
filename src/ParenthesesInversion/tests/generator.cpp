#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <vector>
#include <utility>
#include "../../common/xrand.h"
#include "constraints.hpp"

const int num_of_type = 3;
std::string case_type[num_of_type] = {"10_random_small", "11_random_large", "90_random_kill"};
int num_of_case[num_of_type] = {10, 10, 10};
int min_n[num_of_type] = {1, MAX_N, MAX_N};
int max_n[num_of_type] = {100, MAX_N, MAX_N};
using namespace std;

XRand rnd(283);

// 完全ランダム
string gen1(int n, XRand rnd) {
  string s = "";
  for (int i = 0; i < n; i++) {
    s += rnd.NextInt(0, 1) ? '(' : ')';
  }
  return s;
}

// W 型
string gen2(int n, XRand rnd) {
  string s = "";
  while (s.size() < n) {
    int d = rnd.NextInt(5, 100);
    // 深さが d になるまで
    int dep = 0;
    while (s.size() < n and dep != d) {
      if (rnd.NextInt(0, 10)) {
        dep++;
        s += ')';
      } else {
        dep--;
        s += '(';
      }
    }
    dep = 0;
    while (s.size() < n and dep != d) {
      if (rnd.NextInt(0, 10)) {
        dep++;
        s += '(';
      } else {
        dep--;
        s += ')';
      }
    }
  }
  return s;
}

int main() {
    for(int typenum=0;typenum<num_of_type;++typenum){
        for(int casenum=0;casenum<num_of_case[typenum];++casenum){
            string file_name=case_type[typenum]+"_"+to_string(casenum)+".in";
            ofstream output(file_name);
            int n=rnd.NextInt(min_n[typenum],max_n[typenum]);
            if (n % 2 == 1) n++;
            output<<n<<endl;
            string s=(typenum<=1?gen1:gen2)(n, rnd);
            output<<s<<endl;
            for (int i = 0; i < n; i++) {
              output<<rnd.NextInt(MIN_A, MAX_A);
              if (i + 1 == n) output<<endl;
              else output<<" ";
            }
            output.close();
        }
    }
    return 0;
}
