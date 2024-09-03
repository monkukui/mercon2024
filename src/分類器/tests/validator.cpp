#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int M = inf.readInt(MIN_M, MAX_M);
    inf.readSpace();
    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    char c;
    for(int i=0;i<M;i++){
      for(int j=0;j<N;j++){
        c=inf.readChar();
        ensure(c=='o' || c=='x');
      }
      inf.readEoln();
    }

    inf.readEof();

    return 0;
}
