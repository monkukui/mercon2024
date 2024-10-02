#include <iostream>
#include <string>
#include <cassert>
#include "../../../common/testlib.h"
#include "constraints.hpp"
#define ll long long
using namespace std;

// ============union_find_tree===============
struct union_find {
  vector<ll> par;
  vector<ll> tree_rank;
  vector<ll> num;

  union_find(ll n)
  {
    par = vector<ll>(n);
    num = vector<ll>(n, 1);
    tree_rank = vector<ll>(n);
    for (ll i = 0; i < n; ++i)
    {
      par.at(i) = i;
      tree_rank.at(i) = 0;
    }
  }

  ll find(ll x)
  {
    if (par.at(x) == x)
    {
      return x;
    }
    else
    {
      return par.at(x) = find(par.at(x));
    }
  }

  ll get_num(ll x) {
    return num.at(find(x));
  }

  void unite(ll x, ll y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
    {
      return;
    }
    if (tree_rank.at(x) < tree_rank.at(y))
    {
      par.at(x) = y;
      num.at(y) = num.at(x) + num.at(y);
    }
    else
    {
      par.at(y) = x;
      num.at(x) = num.at(x) + num.at(y);
      if (tree_rank.at(x) == tree_rank.at(y))
      {
        tree_rank.at(x)++;
      }
    }
  }

  bool same(ll x, ll y)
  {
    return find(x) == find(y);
  }
};
// =======================================

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
    union_find uf(M);
    for (ll i = 0; i < M - 1; ++i) {
        int x = inf.readInt(1, M);
        inf.readSpace();
        int y = inf.readInt(1, M);
        uf.unite(x - 1, y - 1);
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
    bool is_tree = true;
    for (ll i = 0; i < M; ++i) {
        if (!uf.same(0, i)) {
            is_tree = false;
        }
    }
    if (!is_tree) {
        quitf(_wa, "error: input is not tree");
    }

    inf.readEof();
    return 0;
}
