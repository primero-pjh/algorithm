#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

set<char> s;
map<char, int> m;
int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		s.insert(str[i]);
	}

	char prev = str[0];
	string new_str = string(1, prev);
	for (int i = 1; i < str.size(); i++) {
		if (str[i] != prev) {
			new_str += str[i];
			prev = str[i];
		}
	}
	if (new_str.size() == 1) {
		cout << 0 << "\n";
		exit(0);
	}
	
	int min_value = 1000000;
	for (int i = 0; i < new_str.size(); i++) {
		m[new_str[i]]++;
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		min_value = min(min_value, iter->second);
	}
	cout << min_value;
	return 0;
}