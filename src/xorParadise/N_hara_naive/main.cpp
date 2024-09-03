#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  
  ios::sync_with_stdio(false);
  cin.tie(0);
  
	int k;
	cin >> k;
	vector<int> n(k);
	for (int i=0;i<k;i++) {
		cin >> n[i];
	}
	vector<vector<long long>> a(k);
	for (int i=0;i<k;i++) {
		for (int j=0;j<n[i];j++) {
			long long val;
			cin >> val;
			a[i].emplace_back(val);
		}
	}
	set<long long> s;
	for (int i=0;i<k;i++) {
		for (int j=0;j<(1LL<<n[i]);j++) {
			long long tmp = 0;
			for (int l=0;l<n[i];l++) {
				if (j&(1LL<<l)) {
					tmp ^= a[i][l];
				}
			}
			s.insert(tmp);
		}
	}
	cout << s.size() << endl;
}
