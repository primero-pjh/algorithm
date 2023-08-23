#include <iostream>
#include <set>

using namespace std;

set<int> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << " ";
	}
	return 0;
}