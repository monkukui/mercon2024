#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> DXC;
  for (ll i = 0; i < N; ++i) {
    ll x, d, c;
    cin >> x >> d >> c;
    DXC.push_back({d, x, c});
  }
  sort(DXC.begin(), DXC.end());
  set<vector<ll>, greater<>> best;// {total_c, x, d}
  ll max_best_size = 1000;
  best.insert({0, 1, 1});
  for (ll i = 0; i < DXC.size(); ++i) {
    ll d = DXC.at(i).at(0), x = DXC.at(i).at(1), c = DXC.at(i).at(2);
    vector<vector<ll>> temp_best;
    ll cnt = 0;
    ll max_best = 0;
    for (auto itr = best.begin(); itr != best.end(); itr++) {
      vector<ll> nbest = *itr;
      ll nx = nbest.at(1), nd = nbest.at(2);
      if (abs(x - nx) <= (d - nd)) {
        max_best = max(max_best, nbest.at(0));
      }
      cnt += 1;
      if (cnt == max_best_size) {
        break;
      }
    }
    temp_best.push_back({max_best + c, x, d});
    for (ll j = 0; j < temp_best.size(); ++j) {
      best.insert(temp_best.at(j));
    }
  }
  cout << (*best.begin()).at(0) << endl;
}
