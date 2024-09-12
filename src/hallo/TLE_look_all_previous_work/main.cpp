#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

bool can_reach(vector<ll> from, vector<ll> to) {
  ll day_dif = to.at(0) - from.at(0);
  ll x_dif = abs(to.at(1) - from.at(1));
  return (x_dif <= day_dif);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> DXC;
  ll min_NX = 0;
  ll min_ND = 0;
  DXC.push_back({1, 1, 0});
  for (ll i = 0; i < N; ++i) {
    ll x, d, c;
    cin >> x >> d >> c;
    DXC.push_back({d, x, c});
  }
  sort(DXC.begin(), DXC.end());
  vector<ll> dp(N + 1, -1);
  dp.at(0) = 0;
  for (ll i = 1; i < N + 1; ++i) {
    for (ll j = 0; j < i; ++j) {
      if (dp.at(j) == -1) {
        continue;
      }
      if (can_reach(DXC.at(j), DXC.at(i))) {
        dp.at(i) = max(dp.at(i), dp.at(j) + DXC.at(i).at(2));
      }
    }
  }
  ll ans = 0;
  for (ll i = 0; i < dp.size(); ++i) {
    ans = max(ans, dp.at(i));
  }
  cout << ans << endl;
}
