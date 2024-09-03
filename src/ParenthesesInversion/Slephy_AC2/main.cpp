//#define _GLIBCXX_DEBUG
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

#include <algorithm>
#include <array>
#include <cassert>
#include <type_traits>
#include <vector>


#ifdef _MSC_VER
#include <intrin.h>
#endif


using ll = long long;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
// const int MOD = (int)1e9 + 7;
// const int MOD = (int)998244353;
const int INF = (int)1e9 + 1001010;
const ll llINF = (ll)4e18 + 11000010;
const double PI = 3.14159265358979;
const double EPS = 1e-10;
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define endn "\n"
#define SUM(v) accumulate(ALL(v), 0LL)
#define MIN(v) *min_element(ALL(v))
#define MAX(v) *max_element(ALL(v))
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

template<typename T,typename U> istream & operator >> (istream &i,pair<T,U> &A){i>>A.first>>A.second; return i;} // pairでの入力受取
template<typename T> istream & operator >> (istream &i,vector<T> &A){for(auto &I:A){i>>I;} return i;} // vectorでの入力受取
template<typename T,typename U> ostream & operator << (ostream &o,const pair<T,U> &A){o<<A.first<<" "<<A.second; return o;} // pairの出力
template<typename T> ostream & operator << (ostream &o,const vector<T> &A){int i=A.size(); for(auto &I:A){o<<I<<(--i?endn:"");} return o;} // vectorの出力
template<typename T,typename U>bool chmax(T &a,const U &b){return ((a<b) ? (a=b, true) : false);}
template<typename T,typename U>bool chmin(T &a,const U &b){return ((a>b) ? (a=b, true) : false);}

ll ceil(ll a, ll b){return (a+b-1) / b;};

// 想定解
// まず前半と後半を区切る適切な場所を調べる
// 両端から区切り位置までpriority_queue、仕上げは必要ない
// O(NlogN)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    assert(n%2 == 0);
    string _s; cin >> _s;
    vector<int> s(n); // '(' -> 1,  ')' -> -1
    for(int i = 0; i < n; i++){
        s[i] = (_s[i] == '(' ? 1 : -1);
    }
    vector<int> a(n); cin >> a;

    // pqg<pair<int, int>> pq[2];

    int border = 0;
    {
        int sum = 0, mi = 0;
        for(int i = 0; i < n; i++){
            sum += s[i];
            if(chmin(mi, sum)) border = i+1;
        }
    }

    // 前半と後半に分けて考える
    // 両端から走査していき、外向きの括弧の個数が内向きの括弧の個数を超えたとき、
    // ここまでの外向き括弧のうちで最もコストの小さいものをひっくり返す
    ll ans = 0;
    for(int i = 0; i < 2; i++){
        // 前半、または後半のみを取り出す
        vector<int> sub;
        if(i == 0) sub = {s.begin(), s.begin()+border};
        else{
            sub = {s.rbegin(), s.rbegin()+(n-border)};
            for(auto &_sub : sub) _sub *= -1;
        }

        // 括弧の個数を数えつつ、必要があればひっくり返す
        int count = 0; 
        pqg<int> pq;
        for(int j = 0; j < sub.size(); j++){
            int index = (i == 0 ? j : n-j-1);

            count += sub[j];
            if(sub[j] == -1) pq.emplace(a[index]);

            if(count < 0){
                auto cost = pq.top(); pq.pop();
                ans += cost;
                count += 2;
            }
        }
    }

    cout << ans << endl;
    return 0;
}