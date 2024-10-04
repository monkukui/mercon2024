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
    int K = inf.readInt(1, N);
    inf.readEoln();

    union_find uf(N);
    for (int i = 0; i < N - 1; ++i) {
        int u = inf.readInt(1, N);
        inf.readSpace();
        int v = inf.readInt(1, N);
        if (!(u < v)) {
          quitf(_wa, "check input u < v");
        }
        inf.readEoln();
        u -= 1, v -= 1;
        uf.unite(u, v);
    }

    bool is_tree = true;
    for (ll i = 0; i < N; ++i) {
        if (!uf.same(0, i)) {
            is_tree = false;
        }
    }
    if (!is_tree) {
        quitf(_wa, "check input is tree failed");
    }

    set<int> X;
    for (int i = 0; i < N; ++i) {
        int x = inf.readInt(1, N);
        X.insert(x);
        if (i != N - 1) {
            inf.readSpace();
        }
    }
    inf.readEoln();
    if (X.size() != N) {
        quitf(_wa, "check all X differ failed");
    }

    inf.readEof();
    return 0;
}
