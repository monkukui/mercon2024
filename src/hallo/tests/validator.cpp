#include <bits/stdc++.h>
// #include <atcoder/modint>
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define INF 2000000000000000000
#define ll long long
#define ull unsigned long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const double PI = 3.141592653589793238462643383279;
#include "../../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

bool AC = true;
void check(bool condition) {
  AC = (AC && condition);
}

int main() {
  registerValidation();

  int N = inf.readInt(MIN_NM, MAX_NM);
  inf.readSpace();
  int M = inf.readInt(MIN_NM, MAX_NM);
  inf.readEoln();

  map<pll, bool> mp;
  for (ll i = 0; i < N; ++i) {
    int x = inf.readInt(MIN_XC, MAX_XC);
    inf.readSpace();
    int d = inf.readInt(MIN_NM, M);
    inf.readSpace();
    int c = inf.readInt(MIN_XC, MAX_XC);
    inf.readEoln();
    if (mp.find({x, d}) != mp.end()) {
      quitf(_wa, "error: same input x, d");
    }
    ensure(mp.find({x, d}) == mp.end());
    mp[{x, d}] = true;
  }
  inf.readEof();
  return 0;
}
