#include <iostream>
#include <string>
#include <cassert>
#include "../../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
  registerValidation();

  int N = inf.readInt(MIN_NM, MAX_NM);
  inf.readSpace();
  int M = inf.readInt(MIN_NM, MAX_NM);
  inf.readEoln();
  for (int i = 0; i < N; ++i) {
    int x = inf.readInt(MIN_XY, MAX_XY);
    inf.readSpace();
    int y = inf.readInt(MIN_XY, MAX_XY);
    inf.readEoln();
    if (!(x <= y)) {
      quitf(_wa, "x <= y check failed");
    }
  }
  for (int i = 0; i < M; ++i) {
    int z = inf.readInt(MIN_Z, MAX_Z);
    inf.readEoln();
  }

  inf.readEof();

  return 0;
}
