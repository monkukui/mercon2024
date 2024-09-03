#include <cassert>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <queue>
using namespace std;

template<typename T>
bool chmin(T& x, const T& y){
  if(x < y) return false;
  x = y;
  return true;
}

int main(){
  int n;
  cin >> n;
  vector<int> ab(2*n);
  for(int i = 0; i < n; ++i)
    cin >> ab[i];
  for(int i = 0; i < n; ++i)
    cin >> ab[i+n];
  assert(n < 7);
  auto alice_win = [](vector<int> ab){
    int n = ab.size()/2;
    for(int i = 0; i < n; ++i){
      if(ab[i] < ab[i+n]) return false;
    }
    return true;
  };

  map<vector<int>,int> memo;
  priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<>> pq;
  const int INF = 1e9;
  int ans = INF;
  pq.emplace(0,ab);
  memo[ab] = 0;
  while(pq.size()){
    auto [t,ab_] = pq.top();
    pq.pop();
    if(memo.count(ab_) and t > memo[ab_])
      continue;
    if(t >= ans) continue;
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < n; ++j){
        swap(ab_[i],ab_[j+n]);
        if(alice_win(ab_))
          chmin(ans,t+1);
        if((!memo.count(ab_)) or t+1 < memo[ab_]){
          memo[ab_] = t+1;
          pq.emplace(t+1,ab_);
        }
        swap(ab_[i],ab_[j+n]);
      }
    }
  }
  
  cout << ans << endl;

  // for(auto [ab_,c] : memo){
  //   if(alice_win(ab_) and ans == c){
  //     cerr << endl;
  //     for(int i = 0; i < n; ++i)
  //       cerr << ab_[i] << " ";
  //     cerr << endl;
  //     for(int i = 0; i < n; ++i)
  //       cerr << ab_[i+n] << " ";
  //     cerr << endl;
  //   }
  // }

}
