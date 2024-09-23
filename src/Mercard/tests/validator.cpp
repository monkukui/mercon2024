#include <iostream>
#include <string>
#include <cassert>
#include "../../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(MIN_N, MAX_N);
    inf.readSpace();
    int X = inf.readInt(MIN_X, MAX_X);
    inf.readEoln();

    for (int i = 0; i < N; i++) {
      int A = inf.readInt(MIN_A, X);
      if (i != N - 1) {
        inf.readSpace();
      }
    }
    inf.readEoln();

    inf.readEof();

    return 0;
}
