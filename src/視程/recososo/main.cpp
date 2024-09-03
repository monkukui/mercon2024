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
    vector<pair<ll,ll>> ch;
    for(int i=0;i<n;i++){
        if(ch.size()<2) ch.push_back({i,h[i]});
        else{
            pair<ll,ll> c={i,h[i]};
            while(ch.size()>=2&&!cnv(ch[ch.size()-2],ch[ch.size()-1],c)){
                ch.pop_back();
            }
            ch.push_back(c);
        }
    }
    ll ans=0;
    for(int i=0;i<ch.size();i++) chmax(ans,ch[i+1].first-ch[i].first);
    cout << ans << '\n';
    return 0;
}