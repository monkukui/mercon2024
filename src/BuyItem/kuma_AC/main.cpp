#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#define ll long long
using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<vector<ll>> huv;
    for (ll i = 0; i < N; ++i) {
        ll u, v, h;
        cin >> u >> v >> h;
        huv.push_back({h, u, v});
    }
    sort(huv.rbegin(), huv.rend());
    map<ll, bool> already_sold;
    vector<vector<ll>> ans;
    for (ll i = 0; i < N; ++i) {
        ll h = huv.at(i).at(0), u = huv.at(i).at(1), v = huv.at(i).at(2);
        if (already_sold.find(v) != already_sold.end()) {
            continue;
        }
        already_sold[v] = true;
        ans.push_back({v, u});
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (ll i = 0; i < ans.size(); ++i) {
        cout << ans.at(i).at(0) << ' ' << ans.at(i).at(1) << endl;
    }
}
