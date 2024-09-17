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

    char c;
    for(int i=0;i<N;i++){
      c=inf.readChar();
      ensure(c=='A' || c=='N');
    }
    inf.readEoln();

    inf.readEof();

    return 0;
}
