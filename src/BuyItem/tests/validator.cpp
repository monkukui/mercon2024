#include <iostream>
#include <string>
#include <cassert>
#include "../../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(MIN_N, MAX_N);
    inf.readEoln();

    map<pair<int, int>, bool> uv_map;
    map<pair<int, int>, bool> hv_map;

    for (int i = 0; i < N; i++) {
        int u = inf.readInt(MIN_U, MAX_U);
        inf.readSpace();
        int v = inf.readInt(MIN_V, MAX_V);
        inf.readSpace();
        int h = inf.readInt(MIN_H, MAX_H);
        inf.readEoln();
        if (uv_map.find(pair<int, int>{u, v}) != uv_map.end()) {
            quitf(_wa, "error: same input u, v");
        }
        if (hv_map.find(pair<int, int>{h, v}) != hv_map.end()) {
            quitf(_wa, "error: same input h");
        }
        uv_map[pair<int, int>{u, v}] = true;
        hv_map[pair<int, int>{h, v}] = true;
    }
    inf.readEof();
    return 0;
}
