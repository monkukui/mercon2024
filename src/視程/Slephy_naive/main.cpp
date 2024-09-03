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

// 愚直解
// O(N^2)

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> h(n); cin >> h;

    int ans = 0;
    auto traverse = [&](const vector<ll> &h){
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                ll dx = j-i;
                ll dy = h[j] - h[i];
                
                bool ok = true;
                for(int k = i+1; k < j; k++){
                    ll kdx = k-i;
                    ll kdy = h[k] - h[i];
                    if(dy*kdx < dx*kdy){
                        ok = false;
                        break;
                    }
                }

                if(ok) chmax(ans, j-i);
            }
        }
    };

    traverse(h);
    reverse(ALL(h));
    traverse(h);

    cout << ans << endl;
    return 0;
}