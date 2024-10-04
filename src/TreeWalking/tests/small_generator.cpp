#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <vector>
#include <utility>
#include <random>
#include <set>
#include "../../common/xrand.h"
#define ll long long
using namespace std;

XRand Rnd(334);

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

void random_small_N(int casenum) {
    std::string file_name="01_random_small_"+std::to_string(casenum)+".in";
    std::ofstream output(file_name);

    int N = Rnd.NextInt(1, 8), K = Rnd.NextInt(1, N);
    output<< N << ' ' << K << std::endl;
    vector<int> vec;
    for (int i = 0; i < N; ++i) {
        vec.push_back(i + 1);
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);
    union_find uf(N);
    for (ll i = 0; i < N - 1; ++i) {
        while (true) {
            int u = Rnd.NextInt(1, N - 1);
            int v = Rnd.NextInt(u + 1, N);
            if (!uf.same(u - 1, v - 1)) {
                uf.unite(u - 1, v - 1);
                output << u << ' ' << v << endl;
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        output<< vec.at(i);
        if (i != N - 1) {
            output << ' ';
        }
    }
    output << std:: endl;
}

int main() {
    for (int i = 0; i < 5; ++i) {
        random_small_N(i);
    }
    return 0;
}
