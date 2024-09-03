#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();
    inf.readLong(MIN_N, MAX_N);
    inf.readEoln();
    inf.readEof();
    return 0;
}