#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int K = inf.readInt(MIN_K, MAX_K);
    inf.readEoln();
    vector<int> a(K);
    for (int i=0;i<K;i++){
        if(i) inf.readSpace();
        a[i]=inf.readInt(MIN_N, MAX_N);
    }
    inf.readEoln();
    for (int i=0;i<K;i++){
        for (int j=0;j<a[i];j++){
            if(j) inf.readSpace();
            long long f=inf.readLong(MIN_A,MAX_A);
        }
        inf.readEoln();
    }

    inf.readEof();

    return 0;
}
