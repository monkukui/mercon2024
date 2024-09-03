// #include <bits/stdc++.h>
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <iomanip> // setprecision
#include <complex> // complex
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];
    

    //yokoo = 横1行に含まれるoの個数(累積和)
    //yokox = 横1行に含まれるxの個数(累積和)
    //tateo = 縦1列に含まれるoの個数(累積和)
    //tatex = 縦1列に含まれるxの個数(累積和)
    vector<int> yokoo(m, 0), tateo(n, 0);
    vector<int> yokox(m, 0), tatex(n, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'o') yokoo[i]++;
        }
        yokox[i] = n - yokoo[i];
        if (i > 0) {
            yokoo[i] += yokoo[i-1];
            yokox[i] += yokox[i-1];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[j][i] == 'o') tateo[i]++;
        }
        tatex[i] = m - tateo[i];
        if (i > 0) {
            tateo[i] += tatex[i-1];
            tatex[i] += tatex[i-1];
        }
    }

    //横に区切る場合を計算
    int ans = 1<<30;
    for (int i = 1; i < m-1; i++) {
        //区切った線の上側がo領域の場合
        int sum = 0;
        sum += yokox[i] + (yokoo[m-1] - yokoo[i]);
        ans = min(ans, sum);

        //区切った線の上側がx領域の場合
        sum = 0;
        sum += yokoo[i] + (yokox[m-1] - yokox[i]);
        ans = min(ans, sum);
    }

    //縦に区切る場合を計算
    for (int i = 1; i < n-1; i++) {
        //区切った線の左側がo領域の場合
        int sum = 0;
        sum += tatex[i] + (tateo[n-1] - tateo[i]);
        ans = min(ans, sum);

        //区切った線の左側がx領域の場合
        sum = 0;
        sum += tateo[i] + (tatex[n-1] - tatex[i]);
        ans = min(ans, sum);
    }
    

    cout << ans << '\n';
    return 0;
}
