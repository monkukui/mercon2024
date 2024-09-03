// #include<bits/stdc++.h>
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
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
// const int mod=1e9+7;
const int mod=998244353;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};

bool cnv(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
    return (b.second-a.second)*(c.first-a.first)>(c.second-a.second)*(b.first-a.first);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    vector<ll> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            bool can=true;
            for(int k=i+1;k<j;k++){
                if(cnv({i,h[i]},{k,h[k]},{j,h[j]})) can=false;
            }
            if(can) chmax(ans,j-i);
        }
    }
    cout << ans << endl;
    return 0;
}