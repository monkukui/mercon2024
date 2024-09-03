#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(MIN_N, MAX_N);
    inf.readSpace();

    int K = inf.readInt(MIN_K, MAX_K);
    if (N <= 20) ensure(K <= (1<<N));
    inf.readEoln();

    inf.readEof();

    return 0;
}
