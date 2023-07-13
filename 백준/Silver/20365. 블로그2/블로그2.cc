#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
map<char, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	string str;
	getline(cin, str);

	char prev = str[0];
	int cnt = 1;
	string new_str;
	new_str += prev;
	for (int i = 1; i < n; i++) {
		if (prev != str[i]) {
			new_str += str[i];
			prev = str[i];
		}
	}
	int res = n;
	m['B'] = 0;
	m['R'] = 0;
	for (int i = 0; i < new_str.size(); i++) {
		m[new_str[i]]++;
	}

	//case2 B
	res = min(1 + m['R'], res);
	//case2 R
	res = min(1 + m['B'], res);

	cout << res << "\n";
	return 0;
}