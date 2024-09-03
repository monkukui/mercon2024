#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
  registerValidation();
  long long n = inf.readLong(MIN_N,MAX_N);
  inf.readEoln();
  for(int i = 0; i < n; ++i){
    long long a = inf.readLong(MIN_V,MAX_V);
    if(i+1 < n) inf.readSpace();
  }
  inf.readEoln();
  for(int i = 0; i < n; ++i){
    long long a = inf.readLong(MIN_V,MAX_V);
    if(i+1 < n) inf.readSpace();
  }
  inf.readEoln();
  inf.readEof();
}
