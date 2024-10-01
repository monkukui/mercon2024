#include <iostream>
#include <string>
#include <cassert>
#include "../../../common/testlib.h"
#include "constraints.hpp"
#define ll long long
using namespace std;

int main(){
    registerValidation();

    ll W = inf.readLong(MIN_WHT, MAX_WHT);
    inf.readSpace();
    ll H = inf.readLong(MIN_WHT, MAX_WHT);
    inf.readSpace();
    ll T = inf.readLong(MIN_WHT, MAX_WHT);
    inf.readEoln();

    ll sx = inf.readLong(MIN_XY, W);
    inf.readSpace();
    ll sy = inf.readLong(MIN_XY, H);
    inf.readEoln();

    inf.readEof();
    return 0;
}
