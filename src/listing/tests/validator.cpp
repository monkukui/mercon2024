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
    int P = inf.readInt(MIN_PC, MAX_PC);
    inf.readEoln();

    for (int i = 0; i < N; i++) {
      int C = inf.readInt(MIN_PC, MAX_PC);
      inf.readSpace();
      string S = inf.readString();//Eolnも読まれる
      assert((S == "on_sale" || S == "sold_out", "check input S"));
    }
    inf.readEof();

    return 0;
}
