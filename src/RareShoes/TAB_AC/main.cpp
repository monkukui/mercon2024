#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  char a = 'A';
  for(const auto& c : s){
    if(c == a) continue;
    ++ans;
    a = c;
  }
  if(a == 'A') --ans;
  ans /= 2;
  cout << ans << '\n';
}
