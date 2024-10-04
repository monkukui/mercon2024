//ulimit -S -s 48576 が必要
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
#define INF 500000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

vector<string> pos;
ll N, K;
vector<ll> X;
vector<vector<ll>> connection;
vector<bool> already;
vector<ll> ans;

vector<ll> calc_min_dict(vector<ll> &V) {
  vector<ll> result;
  ll n = V.size();
  
  // 割り当てることができる要素の残数
  ll toPick = K;
  
  // 現在の位置から残りの要素でKを作れるかどうかを判定するための変数
  ll remainingElements = n;
  
  for(ll i = 0; i < n; ++i) {
      // 現在の要素を追加する場合、既に追加されている要素結果からポップできるかどうかを確認
      while(!result.empty() && result.back() > V.at(i) && (remainingElements - 1) >= toPick) {
          result.pop_back();
          toPick++;
      }
      
      // 必要な要素数が追加されていない場合、現在の要素を結果に追加
      if(toPick > 0) {
          result.push_back(V.at(i));
          toPick--;
      }
      
      // 残りの要素数を減らす
      remainingElements--;
  }
  
  return result;
}

void dfs(ll now, vector<ll> &V) {
  // cout << now << endl;
  ll cnt = 0;
  for (ll i = 0; i < connection.at(now).size(); ++i) {
    ll next = connection.at(now).at(i);
    if (already.at(next)) {
      continue;
    }
    V.push_back(X.at(next));
    already.at(next) = true;
    dfs(next, V);
    V.pop_back();
    cnt += 1;
  }
  if (cnt == 0 && V.size() >= K) {
    ans = min(ans, calc_min_dict(V));
  }
}

int main() {
  cin >> N >> K;
  connection = vector<vector<ll>>(N);
  already = vector<bool>(N, false);
  X = vector<ll>(N);
  for (ll i = 0; i < K; ++i) {
    ans.push_back(INF);
  }
  for (ll i = 0; i < N - 1; ++i) {
    ll u, v;
    cin >> u >> v;
    u -= 1, v -= 1;
    connection.at(u).push_back(v);
    connection.at(v).push_back(u);
  }
  for (ll i = 0; i < N; ++i) {
    cin >> X.at(i);
  }
  vector<ll> V = {X.at(0)};
  already.at(0) = true;
  stack<ll> st;
  dfs(0, V);
  if (ans.at(0) == INF) {
    cout << -1 << endl;
  }
  else {
    for (ll i = 0; i < ans.size(); ++i) {
      cout << ans.at(i);
      if (i != K - 1) {
        cout << ' ';
      }
    }
    cout << endl;
  }
}
