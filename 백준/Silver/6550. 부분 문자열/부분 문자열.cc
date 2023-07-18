#include <iostream>
#include <string>
#include <set>

using namespace std;

set<char> item;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s, t;
	while (cin >> s >> t) {
		for (int i = 0; i < s.size(); i++) {
			item.insert(s[i]);
		}
		string result = "";
		int idx = 0;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == s[idx]) {
				result += t[i];
				idx++;
			}
		}
		if (result == s) {
			cout << "Yes" << "\n";
		}
		else {
			cout << "No" << "\n";
		}
	}
	return 0;
}