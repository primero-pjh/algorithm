#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	string replace = "wghuvijxpqrstacdebfklmnoyz";
	cin.ignore();
	while (t--) {
		string str;
		map<char, int> m;
		set<char> s;
		getline(cin, str);
		int max_value = 0;
		for (int i = 0; i < str.size(); i++) {
			if (isalpha(str[i])) {
				m[str[i]]++;
				max_value = max(max_value, m[str[i]]);
			}
		}
		vector<char> v;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if (iter->second == max_value) {
				v.push_back(iter->first);
			}
		}
		if (v.size() == 1) {
			cout << v[0] << "\n";
		}
		else {
			cout << '?' << "\n";
		}
	}
	return 0;
}