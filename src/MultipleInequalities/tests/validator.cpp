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
        int a = inf.readInt(1, N);
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
    vector<ll> B(M);
    for (ll i = 0; i < M; ++i) {
        int b = inf.readInt(1, M);
        B.at(i) = b;
        if (i != M - 1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    sort(B.begin(), B.end());
    bool b_ok = true;
    for (ll i = 0; i < M; ++i) {
        if (B.at(i) != i + 1) {
            b_ok = false;
        }
    }
    if (!b_ok) {
        quitf(_wa, "error: B not permutation");
    }

    inf.readEof();
    return 0;
}
