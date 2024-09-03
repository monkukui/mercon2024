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

    int M = inf.readInt(MIN_M, MAX_N);
    inf.readEoln();

    for(int i = 0; i < N; i++){
        inf.readInt(MIN_A, MAX_A);
        if(i < N-1) inf.readSpace();
    }
    inf.readEoln();

    inf.readEof();

    return 0;
}
