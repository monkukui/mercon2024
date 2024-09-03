#include <iostream>
#include <string>
#include <cassert>
#include "../../common/testlib.h"
#include "constraints.hpp"
using namespace std;

int main(){
  registerValidation();
  int n = inf.readInt(MIN_N, MAX_N);
  inf.readSpace();
  int m = inf.readInt(1, min(n * (n - 1) / 2, 200000));
  inf.readEoln();
  vector<vector<int>> g(n);
  set<pair<int, int>> st;
  for (int i = 0; i < m; i++) {
    int a = inf.readInt();
    inf.readSpace();
    int b = inf.readInt();
    inf.readEoln();
    // 自己ループがないこと
    ensure(a != b);
    if (a > b) swap(a, b);
    a--;
    b--;
    st.insert({a, b});
    g[a].push_back(b);
    g[b].push_back(a);
  }

  // 多重辺がないこと
  ensure(st.size() == m);
  int k = inf.readInt(1, n);
  inf.readEoln();
  vector<int> v;
  for (int i = 0; i < k; i++) {
    v.push_back(inf.readInt(1, n));
    if (i + 1 == k) {
      inf.readEoln();
    } else {
      inf.readSpace();
    }
  }

  // 連結であること
  vector<bool> visited(n, false);
  auto dfs = [&](auto &&self, int cur, int par) -> void {
    visited[cur] = true;
    for (auto nxt : g[cur]) {
      if (nxt == par) continue;
      if (visited[nxt]) continue;
      self(self, nxt, cur);
    }
  };
  dfs(dfs, 0, -1);
  for (auto c : visited) {
    ensure(c);
  }

  // isSorted
  for (int i = 1; i < v.size(); i++) {
    ensure(v[i - 1] < v[i]);
  }

  int s = inf.readInt(1, n);
  inf.readSpace();
  int t = inf.readInt(1, n);
  inf.readEoln();
  // ensure: s \in {v_1, ..., v_k}
  bool exist = false;
  for (auto c : v) {
    exist |= (s == c);
  }
  ensure(exist);
  inf.readEof();
  return 0;
}
