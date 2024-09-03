#include <iostream>
#include <cassert>
#include "../../common/testlib.h"
#include "../../common/xrand.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    for(int i = 0; i < N; i++){
        int A_i = inf.readInt(MIN_A, MAX_A);
        if(i < N-1){
            inf.readSpace();
        }else{
            inf.readEoln();
        }
    }
    
    inf.readEof();

    return 0;
}