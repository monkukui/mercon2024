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
    map<int, bool> h_map;

    for (int i = 0; i < N; i++) {
        int u = inf.readInt(MIN_U, MAX_U);
        inf.readSpace();
        int v = inf.readInt(MIN_V, MAX_V);
        inf.readSpace();
        int h = inf.readInt(MIN_H, MAX_H);
        inf.readEoln();
        assert((uv_map.find(pair<int, int>{u, v}) == uv_map.end(), "check input u, v"));
        assert((h_map.find(h) == h_map.end(), "check input h"));
        uv_map[pair<int, int>{u, v}] = true;
        h_map[h] = true;
    }
    inf.readEof();
    return 0;
}
