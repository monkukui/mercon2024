#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <numeric>
#define INF 5000000000000000000
#define ll long long
#define ld long double
#define pll pair<ll, ll>
using namespace std;

//==================param==========
ll time_end = 1900;
//=================================
mt19937 mt{0};
ll N, X;
vector<ll> A;
ld start;

ll calc_score(vector<ll> &ans) {
    ll res = 0;
    ll sum_cost = 0;
    for (ll i = 0; i < ans.size(); ++i) {
        ll a = A.at(ans.at(i));
        res += a * (1 + min(2ll, sum_cost / X));
        sum_cost += a;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    start = clock();
    cin >> N >> X;
    uniform_int_distribution<int> random_index(0, N - 1);
    A = vector<ll>(N);
    for (ll i = 0; i < N; ++i) {
        cin >> A.at(i);
    }
    vector<ll> ans(N);
    for (ll i = 0; i < N; ++i) {
        ans.at(i) = i;
    }
    ll max_score = calc_score(ans);
    ll cnt = 0;
    while (true) {
        cnt += 1;
        if (cnt % 100 == 0) {
            clock_t end = clock();
            ld time = (ld)(end - start) / CLOCKS_PER_SEC * 1000.0;
            if (time > time_end) {
                break;
            }
        }
        ll index1 = random_index(mt);
        ll index2 = random_index(mt);
        if (index1 != index2) {
            swap(ans.at(index1), ans.at(index2));
            ll temp_score = calc_score(ans);
            if (temp_score > max_score) {
                max_score = temp_score;
            }
            else {
                swap(ans.at(index1), ans.at(index2));
            }
        }
    }
    cout << max_score << endl;
}
