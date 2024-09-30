#include <iostream>
#include <string>
#include <cassert>
#include "../../../common/testlib.h"
#include "constraints.hpp"
#define ll long long
using namespace std;

int main(){
    registerValidation();

    int N = inf.readInt(MIN_N, MAX_N);
    inf.readSpace();
    int M = inf.readInt(1, N);
    inf.readEoln();

    vector<ll> A(N);
    for (ll i = 0; i < N; ++i) {
        int a = inf.readInt(1, MAX_N);
        A.at(i) = a;
        if (i != N - 1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    sort(A.begin(), A.end());
    bool a_ok = true;
    for (ll i = 0; i < N; ++i) {
        if (A.at(i) != i + 1) {
            a_ok = false;
        }
    }
    if (!a_ok) {
        quitf(_wa, "error: A not permutation");
    }
    map<ll, bool> already_y;
    map<ll, ll> cnt_x;
    for (ll i = 0; i < M - 1; ++i) {
        int x = inf.readInt(1, M);
        inf.readSpace();
        int y = inf.readInt(1, M);
        inf.readEoln();
        if (x == y) {
            quitf(_wa, "error: x and y must be different");
        }
        if (already_y.find(y) != already_y.end()) {
            quitf(_wa, "error: all y must be different");
        }
        if (cnt_x.find(x) == cnt_x.end()) {
            cnt_x[x] = 0;
        }
        if (cnt_x[x] >= 2) {
            quitf(_wa, "error: more than two same x");
        }
        cnt_x[x] += 1;
    }

    inf.readEof();
    return 0;
}
