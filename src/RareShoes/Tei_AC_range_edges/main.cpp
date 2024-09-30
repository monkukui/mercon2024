#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")

#include <random>
#include <iostream>
#include <cstdio>
#include <string>
#include <regex>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <unordered_set>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
#include <bitset>
#include <cstddef>
#include <type_traits>
#include <vector>
#include <sys/time.h>
#define ll long long
#define pll pair<ll, ll>
#define pint pair<int, int>
using namespace std;


// https://kopricky.github.io/code/Asobiba/bipartite_matching_under_range_edges.html
class BM {
private:
    struct edge {
        int l, r;
        edge(const int _l, const int _r) : l(_l), r(_r){}
    };
    const int U, V;
    vector<vector<edge> > G;
    vector<set<int> > layer;
    vector<int> level, que, prv, rasg;
    set<int> st, pst;
    int bfs(){
        int last = -1, qh = 0, qt = 0;
        for(int i = 0; i < U + V; ++i){
            layer[i].clear(), level[i] = -1;
        }
        for(int i = 0; i < U; ++i){
            if(asg[i] < 0) level[i] = 0, que[qt++] = i, prv[i] = -1;
        }
        st = pst;
        while(qh < qt){
            const int u = que[qh++];
            if(u >= U){
                const int v = rasg[u - U];
                if(v >= 0) level[v] = level[u] + 1, que[qt++] = v, prv[v] = u;
                else last = u;
            }else{
                for(const edge& e : G[u]){
                    for(auto it = st.lower_bound(e.l); it != st.end() && *it < e.r;){
                        const int v = *it;
                        layer[level[u]].insert(v), level[U + v] = level[u] + 1;
                        que[qt++] = U + v, prv[U + v] = u, it = st.erase(it);
                    }
                }
            }
        }
        return last;
    }
    bool dfs(const int u){
        if(u >= U){
            if(rasg[u - U] < 0) return true;
            else return dfs(rasg[u - U]);
        }else{
            auto& vers = layer[level[u]];
            for(const edge& e : G[u]){
                for(auto it = vers.lower_bound(e.l); it != vers.end() && *it < e.r;){
                    const int v = *it;
                    it = vers.erase(it);
                    if(dfs(U + v)){
                        asg[u] = v, rasg[v] = u;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    void hint_search(int cur, int& flow){
        ++flow;
        while(cur >= 0){
            level[cur] = -1;
            if(cur >= U){
                layer[level[prv[cur]]].erase(cur - U);
                asg[prv[cur]] = cur - U, rasg[cur - U] = prv[cur];
            }
            cur = prv[cur];
        }
    }
public:
    BM(const int u, const int v)
         : U(u), V(v), G(U + V), layer(U + V), level(U + V), que(U + V), prv(U + V), rasg(V, -1), asg(U, -1){
        for(int i = 0; i < V; ++i) pst.insert(i);
    }
    void add_edge(const int from, const int l, const int r){
        G[from].emplace_back(l, r);
    }
    // asg に左側頂点がどの右側頂点とマッチングされるかが格納される
    vector<int> asg;
    int solve(){
        int flow = 0;
        for(;;){
            const int cur = bfs();
            if(cur < 0) break;
            hint_search(cur, flow);
            for(int i = 0; i < U; ++i){
                if(asg[i] < 0) flow += dfs(i);
            }
        }
        return flow;
    }
};


int main() {
    // 区間辺二部マッチング解 O(N^1.5logN)
    int N, M;
    cin >> N >> M;
    vector<pint> XY(N);
    for (int i = 0; i < N; ++i) {
        cin >> XY.at(i).first >> XY.at(i).second;
    }
    vector<int> Z(M);
    for (int i = 0; i < M; ++i) {
        cin >> Z.at(i);
    }

    sort(Z.begin(), Z.end());

    BM bipartite(N, M);
    for (int i = 0; i < N; ++i) {
        int start = XY.at(i).first;
        int end = XY.at(i).second;
        // z内についてstart以上の最小の要素のインデックスをlower_boundで求める
        int idx1 = lower_bound(Z.begin(), Z.end(), start) - Z.begin();
        if (idx1 == M) continue;
        // z内についてendより大きい最小の要素のインデックスをlower_boundで求める
        int idx2 = lower_bound(Z.begin(), Z.end(), end+1) - Z.begin();
        if (idx1 == idx2) continue;
        bipartite.add_edge(i, idx1, idx2);
    }
    int ans = bipartite.solve();
    cout << ans << endl;
}
