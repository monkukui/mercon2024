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
ll END_TIME = 1900;
const ld T0 = 10000;
const ld T1 = 1;
const ll refresh_rate = 100;
//=================================
mt19937 mt{0};

ld T = T0;
uniform_real_distribution<ld> random_float(0, 1);
const ld e = 2.718281828459045;

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
    ll now_score = calc_score(ans);
    ll max_score = now_score;
    ll cnt = 0;
    ld t;
    while (true) {
        cnt += 1;
        if (cnt % refresh_rate == 0) {
            clock_t end = clock();
            ld time = (ld)(end - start) / CLOCKS_PER_SEC * 1000.0;
            t = time / (ld)END_TIME;
            T = pow(T0, 1 - t) * pow(T1, t);
            if (time >= END_TIME) {
                break;
            }
            if (time > END_TIME) {
                break;
            }
        }
        ll index1 = random_index(mt);
        ll index2 = random_index(mt);
        if (index1 != index2) {
            swap(ans.at(index1), ans.at(index2));
            ll new_score = calc_score(ans);
            if (new_score > now_score) {
                now_score = new_score;
                max_score = max(max_score, new_score);
            }
            else if (random_float(mt) < pow(e, new_score - now_score / (ld)T)) {
                now_score = new_score;
                max_score = max(max_score, now_score);
            }
            else {
                swap(ans.at(index1), ans.at(index2));
            }
        }
    }
    cout << max_score << endl;
}
