#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n,mod=998244353,ans=0;cin>>n;
  vector<long long> a(n);
  map<int,long long> line;
  for(int i=0;i<n;i++){
      cin>>a[i];
      line[i]=i+a[i];//(現在位置)<line[i]が条件
  }
  vector<long long> B(n);
  iota(B.begin(),B.end(),0);
  do{
    for(int i=0;i<n;i++){
      if(B[i]>=line[i]) break;
      if(i==n-1) ans=(ans+1)%mod;
    }
  }while(next_permutation(B.begin(),B.end()));
  cout<< ans <<endl;
}