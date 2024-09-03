#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    int h;
    for(int i=0;i<N;i++){
      if(i){
        inf.readSpace();
      }
      h=inf.readInt(MIN_H, MAX_H);
    }
    inf.readEoln();

    inf.readEof();

    return 0;
}