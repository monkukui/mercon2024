#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll max_day = 0, max_x = 0;
  ll N, M;
  cin >> N >> M;
  vector<ll> C(N), D(N), X(N);
  // job[{day, x-index}] = max_c
  for (ll i = 0; i < N; ++i) {
    cin >> X.at(i) >> D.at(i) >> C.at(i);
    max_day = max(max_day, D.at(i));
    max_x = max(max_x, X.at(i));
    // change to 0-index
    X.at(i) -= 1, D.at(i) -= 1;
  }
  vector<vector<pll>> job(max_day);
  for (ll i = 0; i < N; ++i) {
    job.at(D.at(i)).push_back({C.at(i), X.at(i)});
  }
  // dp[day][x-index] = max_c_sum
  vector<ll> dp(max_x, -1);
  dp.at(0) = 0;
  for (ll i = 0; i < job.at(0).size(); ++i) {
    if (job.at(0).at(i).second == 0) {
      dp.at(0) = max(dp.at(0), job.at(0).at(i).first);
    }
  }
  for (ll i = 1; i < max_day; ++i) {
    vector<ll> temp(max_x, -1);
    vector<ll> tomorrow_job(max_x, 0);
    for (ll j = 0; j < job.at(i).size(); ++j) {
      tomorrow_job.at(job.at(i).at(j).second) = max(tomorrow_job.at(job.at(i).at(j).second), job.at(i).at(j).first);
    }
    for (ll j = 0; j < max_x; ++j) {
      if (dp.at(j) == -1) {
        continue;
      }
      if (j != 0) {
        temp.at(j - 1) = max(temp.at(j - 1), dp.at(j) + tomorrow_job.at(j - 1));
      }
      temp.at(j) = max(temp.at(j), dp.at(j) + tomorrow_job.at(j));
      if (j != max_x - 1) {
        temp.at(j + 1) = max(temp.at(j + 1), dp.at(j) + tomorrow_job.at(j + 1));
      }
    }
    dp = temp;
  }
  ll ans = 0;
  for (ll i = 0; i < max_x; ++i) {
    ans = max(ans, dp.at(i));
  }
  cout << ans << endl;
}
