#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	int max_value = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		m[str]++;
		max_value = max(max_value, m[str]);
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == max_value) {
			cout << iter->first << "\n";
			exit(0);
		}
	}

	return 0;
}