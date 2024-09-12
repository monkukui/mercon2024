#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
using namespace std;

//---------------------------------------------------------------------------------------------------
// get max 2D segment tree
#define def -1
using V = ll;
V comp(V& l, V& r) { return max(l, r); };
struct SegTree { //[l,r)
    int NV;
    vector<V> val;
    void init(int n) {
        NV = 1;
        while (NV < n) NV *= 2;
        val = vector<V>(NV * 2, def);
    }
    V get(int x, int y, int l, int r, int k) {
        if (r <= x || y <= l) return def; if (x <= l&&r <= y)return val[k];
        auto a = get(x, y, l, (l + r) / 2, k * 2); auto b = get(x, y, (l + r) / 2, r, k * 2 + 1); return comp(a, b);
    }
    V get(int x, int y) { return get(x, y, 0, NV, 1); }
    void update(int i, V v) { i += NV; val[i] = max(val[i], v); while (i>1)i >>= 1, val[i] = comp(val[i * 2], val[i * 2 + 1]); }
    V operator[](int x) { return get(x, x + 1); }
};

struct Healthy2DSegTree {
    int NV;
    vector<SegTree> st;
    vector<vector<int>> index;

    void init(vector<vector<int>> &v) {
        int n = v.size();
        NV = 1; while (NV < n) NV *= 2;
        index.resize(2 * NV);
        rep(i, 0, n) fore(j, v[i]) index[i + NV].push_back(j);
        rrep(i, NV * 2 - 1, 1) {
            sort(index[i].begin(), index[i].end());
            index[i].erase(unique(index[i].begin(), index[i].end()), index[i].end());
            fore(j, index[i]) index[i / 2].push_back(j);
        }
        st.resize(2 * NV);
        rep(i, 1, NV * 2) st[i].init(index[i].size());
    }
    void update(int x, int y, V v) {
        assert(x < NV);
        x += NV;
        while (x) {
            int yy = lower_bound(index[x].begin(), index[x].end(), y) - index[x].begin();
            assert(yy != index[x].size());
            assert(y == index[x][yy]);
            st[x].update(yy, v);
            x >>= 1;
        }
    }
    V get(int sx, int tx, int sy, int ty, int k, int l, int r) {
        assert(k < NV * 2);
        assert(l < r);
        if (r <= sx or tx <= l) return def;
        if (sx <= l and r <= tx) {
            int syy = lower_bound(index[k].begin(), index[k].end(), sy) - index[k].begin();
            int tyy = lower_bound(index[k].begin(), index[k].end(), ty) - index[k].begin();
            return st[k].get(syy, tyy);
        }
        int md = (l + r) / 2;
        V le = get(sx, tx, sy, ty, k * 2, l, md);
        V ri = get(sx, tx, sy, ty, k * 2 + 1, md, r);
        return comp(le, ri);
    }
    V get(int sx, int tx, int sy, int ty) {
        return get(sx, tx, sy, ty, 1, 0, NV);
    }
};
//---------------------------------------------------------------------------------------------------

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> C(N), D(N), X(N);
  vector<pll> use_AB = {{0, 0}};
  ll ab_offset = 0;
  for (ll i = 0; i < N; ++i) {
    cin >> X.at(i) >> D.at(i) >> C.at(i);
    // change to 0-index
    X.at(i) -= 1, D.at(i) -= 1;

    use_AB.push_back({X.at(i) - D.at(i), X.at(i) + D.at(i)});
    ab_offset = min({ab_offset, X.at(i) - D.at(i), X.at(i) + D.at(i)});
  }
  ll max_a = -1, max_b = -1;
  for (ll i = 0; i < use_AB.size(); ++i) {
    use_AB.at(i) = {use_AB.at(i).first - ab_offset, use_AB.at(i).second - ab_offset};
    max_a = max(max_a, use_AB.at(i).first);
    max_b = max(max_b, use_AB.at(i).second);
  }
  vector<vector<int>> index(max_a + 1);
  for (ll i = 0; i < use_AB.size(); ++i) {
    index.at(use_AB.at(i).first).push_back(use_AB.at(i).second);
  }
  Healthy2DSegTree st;
  st.init(index);
  st.update(0 - ab_offset, 0 - ab_offset, 0);
  vector<vector<ll>> DCX(N);
  for (ll i = 0; i < N; ++i) {
    DCX.at(i) = {D.at(i), C.at(i), X.at(i)};
  }
  sort(DCX.begin(), DCX.end());
  ll ans = 0;
  for (ll i = 0; i < DCX.size(); ++i) {
    ll d = DCX.at(i).at(0), c = DCX.at(i).at(1), x = DCX.at(i).at(2);
    ll a = x - d - ab_offset, b = x + d - ab_offset;
    ll today_max = st.get(a, b + 1, a, b + 1);
    if (today_max == -1) {
      continue;
    }
    st.update(a, b, today_max + c);
    ans = max(ans, today_max + c);
  }

  cout << ans << endl;
}
