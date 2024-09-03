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
typedef unsigned long long ll;

#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repp(i, m, n) for(int i = (int)m; i < (int)n; i++)

#define ALL(x) x.begin(),x.end()

#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define keta(x) cout << std::fixed << std::setprecision(15) << (double)x << endl;

const int INF = 1e9;

//以下，色を塗る
vector<vector<int>> A;
set<vector<int>> check;
int N;
void color(int k, vector<int> C, int c){
    if(check.count(C)){
        return;
    }
    if(k == (1<<N)){
        A.push_back(C);
        check.insert(C);
        return;
    }
    C.push_back(c);
    for(int i = 1; i <= (1<<N); i++){
        color(k+1, C, i);
    }
}

// nCkの組み合わせに対して処理を実行する
vector<vector<int>> foreach_comb(int n, int k) {
  vector<vector<int>> ans;
  rep(bits, (1<<n)){
    vector<int> p;
    rep(i, n){
      if((bits & (1<<i))){
        p.push_back(i);
      }
    }
    if(p.size() == k) ans.push_back(p);
  }
  return ans;
}

//i=0,1,...,N-1におけるA0\cupA1・・・\cupAN-1を計算する．
set<int> cup(vector<set<int>> A){
    set<int> ans;

    //和集合を計算
    for(int i = 0; i < A.size(); i++){
        for(auto p : A[i]){
            ans.insert(p);
        }
    }

    return ans;
}

bool solve(int k, vector<int> c){
    set<int> cnt;
    rep(i, c.size()){
        cnt.insert(c[i]);
    }
    if(cnt.size() == k) return true;
    else return false;
}

int many_color(vector<int> c){
    set<int> cnt;
    for(auto p : c){
        cnt.insert(p);
    }
    return cnt.size();
}

int main(){
    int K;
    cin >> N >> K;
    vector<set<int>> Q;

    //Qの作成
    rep(bits, 1<<N){
        set<int> S;
        rep(i, N){
            if(1<<i & bits){
                S.insert(i+1);
            }
        }
        Q.push_back(S);
    }

    //2^N個使って色を塗る
    repp(i, 1, (1<<N)+1){
        color(0, {}, i);
    }

    //2^NからK個選んだ時の組み合わせを列挙
    vector<vector<int>> comb = foreach_comb((1<<N), K);
    int ans = INF;
    //色の全パターンが条件に適合するか確かめる．
    rep(i, A.size()){
        bool ok = true;
        rep(j, comb.size()){
            vector<int> check_c;
            vector<set<int>> check_S;
            for(auto p : comb[j]){
                check_c.push_back(A[i][p]);
                check_S.push_back(Q[p]);
            }

            if(cup(check_S) == Q[Q.size()-1]){
                if(solve(K, check_c) == false) ok = false;
            }
        }
        //色を数える
        if(ok){
            ans = min(ans, many_color(A[i]));
        }
    }

    cout << ans << endl;
}