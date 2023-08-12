#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
set<string> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		sort(str.begin(), str.end());
		if (s.find(str) == s.end()) {
			s.insert(str);
		}
	}
	cout << s.size();
	return 0;
}