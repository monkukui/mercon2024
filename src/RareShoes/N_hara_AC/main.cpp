#include <iostream>
#include <string>
using namespace std;
 
int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  string s;
  cin >> n >> s;
  int cnt = -1;
  int mode = 0;
  for (int i=0;i<n;i++) {
    if (mode == 0 && s[i] == 'N') {
      mode = 1;
      cnt++;
    }
    else if (mode == 1 && s[i] == 'A') {
      mode = 0;
    }
  }
  cout << max(cnt,0) << endl;
}