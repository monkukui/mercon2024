#include <bits/stdc++.h>
#define INF 2000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

//=============segment_tree============================
struct segment_tree {
  int MAX_N;
  ll N;
  int nn;
  vector<ll> dat;
  segment_tree(ll n_) {
    N = n_;
    nn = 1;
    while (nn < n_) {
      nn *= 2;
    }
    MAX_N = nn;
    dat = vector<ll>(2 * MAX_N - 1, -INF);
  }

  void update(ll k, ll a) {
    assert(0 <= k && k < N);
    k += nn - 1;
    dat.at(k) = max(dat.at(k), a);//要変更
    while (k > 0) {
      k = (k - 1) / 2;
      dat.at(k) = max(dat.at(k * 2 + 1), dat.at(k * 2 + 2));//要変更
    }
  }

  ll query(ll a, ll b, ll k = -1, ll l = -1, ll r = -1) {
    assert(0 <= a && a < N && 0 <= b && b <= N);
    if (k == -1 && l == -1 && r == -1) {
      k = 0, l = 0, r = nn;
    }
    if (r <= a || b <= l) {
      return -INF;//要変更
    }
    if (a <= l && r <= b) {
      return dat.at(k);
    }
    else {
      ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
      return max(vl, vr);//要変更
    }
  }
};
//=================================================

bool cmp(vector<ll> &v1, vector<ll> &v2) {
  if (v1.at(0) == v2.at(0)) {
    return v1.at(1) > v2.at(1);
  }
  return v1.at(0) < v2.at(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> ABC;
  ll min_a = 2, min_b = 0;
  for (ll i = 0; i < N; ++i) {
    ll x, d, c;
    cin >> x >> d >> c;
    ABC.push_back({x + d, x - d, c});
    min_a = min(min_a, x + d);
    min_b = min(min_b, x - d);
  }
  ll max_b = 1 - 1 - min_b;
  for (ll i = 0; i < ABC.size(); ++i) {
    ABC.at(i) = {ABC.at(i).at(0) - min_a, ABC.at(i).at(1) - min_b, ABC.at(i).at(2)};
    max_b = max(max_b, ABC.at(i).at(1));
  }
  segment_tree seg(max_b + 2);
  seg.update(1 - 1 - min_b, 0);
  sort(ABC.begin(), ABC.end(), cmp);
  for (ll i = 0; i < ABC.size(); ++i) {
    ll a = ABC.at(i).at(0), b = ABC.at(i).at(1), c = ABC.at(i).at(2);
    ll max_income_from = seg.query(b, max_b + 2);
    if (max_income_from == -INF) {
      continue;
    }
    seg.update(b, max_income_from + c);
  }
  ll ans = seg.query(0, max_b + 2);
  if (ans == -INF) {
    ans = 0;
  }
  cout << ans << endl;
}
