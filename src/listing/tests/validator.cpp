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

    int on_sale_cnt = 0, sold_out_cnt = 0;

    for (int i = 0; i < N; i++) {
      int C = inf.readInt(MIN_PC, MAX_PC);
      inf.readSpace();
      string S = inf.readString();//Eolnも読まれる
      if (!(S == "on_sale" || S == "sold_out")) {
        quitf(_wa, "check input S failed");
      }
      if (S == "on_sale") {
        on_sale_cnt += 1;
      }
      if (S == "sold_out") {
        sold_out_cnt += 1;
      }
    }
    if ((on_sale_cnt == 0) || (sold_out_cnt == 0)) {
      quitf(_wa, "check at least one on_sale and sold_out failed");
    }
    inf.readEof();

    return 0;
}
