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

    int A;
    for(int i = 1; i <= N; i++){
        A = inf.readInt(MIN_A, N-i+1);
        if(i != N) inf.readSpace();
    }

    inf.readEoln();
    inf.readEof();
}