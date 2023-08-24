#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> s;
int main() { 
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str; cin >> str;
	s.insert(str);
	while (str.size() >= 2) {
		str.erase(str.begin());
		s.insert(str);
	}

	for (auto iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << "\n";
	}
	return 0; 
}