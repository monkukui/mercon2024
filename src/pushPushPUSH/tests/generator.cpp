#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <random>
#include <set>
#include "../../common/xrand.h"
#include "constraints.hpp"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

std::random_device seed;
XRand rand(905);

#ifndef ATCODER_DSU_HPP
#define ATCODER_DSU_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

}  // namespace atcoder

#endif  // ATCODER_DSU_HPP


const int min_n_[] = {MIN_N, MIN_N,MIN_N,MIN_N,MIN_N};
const int max_n_[] = {100, MAX_N,MAX_N,MAX_N,MAX_N};

void random_case(ostream &ofs, int case_size){
  const int min_n = min_n_[case_size];
  const int max_n = max_n_[case_size];
  int N = rand.NextInt(min_n,max_n);
  int M = rand.NextInt(N-1,max(N-1,min(100000,N*(N-1)/2)));
  if (case_size==3) M = rand.NextInt(N-1,max(N-1,min(N+10,min(100000,N*(N-1)/2))));
  if (case_size==4) M = N-1;
  ofs << N << " " << M << endl;
  set<pair<int,int>> se;
  atcoder::dsu uni(N);
  rep(i,N-1){
    while(true){
      int a=rand.NextInt(0,N-1),b=rand.NextInt(0,N-1);
      if (a==b) continue;
      if (a>b) swap(a,b);
      if (uni.same(a,b)) continue;
      uni.merge(a,b);
      se.insert(make_pair(a,b));
      ofs << a+1 << " " << b+1 << endl;
      break;
    }
  }
  rep(i,M-(N-1)){
    while(true){
      int a=rand.NextInt(0,N-1),b=rand.NextInt(0,N-1);
      if (a==b) continue;
      if (a>b) swap(a,b);
      if (se.find(make_pair(a,b))!=se.end()) continue;
      se.insert(make_pair(a,b));
      ofs << a+1 << " " << b+1 << endl;
      break;
    }
  }
  int K=rand.NextInt(1,N);
  int S=rand.NextInt(0,N-1);
  int T=rand.NextInt(0,N-1);
  if (case_size==2 || case_size==3 || case_size==4) K=rand.NextInt(max(1,N-5),N);
  set<int> s;
  s.insert(S);
  rep(i,K-1){
    while(true){
      int a=rand.NextInt(0,N-1);
      if (s.find(a)!=s.end()) continue;
      s.insert(a);
      break;
    }
  }
  ofs << K << endl;
  int count=0;
  for (auto it=s.begin();it!=s.end();it++){
    ofs << *it+1 << (count+1 < K ? ' ' : '\n');
    count++;
  }
  ofs << S+1 << " " << T+1 << endl;
}

void generate(ostream &ofs, const string &case_name){
  int case_size = case_name[1] - '0';
  if(case_name[0] == '1'){
    random_case(ofs, case_size);
  }
}

int main(){
  
  vector<string> case_name = {
    "10_random_small_","11_random_large_","12_random_manyblock_","13_random_fewedge_","14_random_tree_"
  };


  vector<int> case_num = {
    5,5,10,25,15
  };


  for (size_t i = 0; i < case_num.size(); i++) {
    for (int j = 0; j < case_num[i]; j++) {
      char id[10];
      sprintf(id, "%02d", j);
      string name = case_name[i] + id + ".in";
      ofstream ofs(name);
      generate(ofs, case_name[i]);
      ofs.close();
    }
  }
  return 0;
}
