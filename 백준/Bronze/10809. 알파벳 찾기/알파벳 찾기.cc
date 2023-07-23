#include <iostream>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string str;
	cin >> str;
	map<char, int> m;
	for (int i = 0; i < str.size(); i++) {
		if (m.find(str[i]) == m.end()) {
			m[str[i]] = i;
		}
	}

	for (int i = 97; i <= 122; i++) {
		if (m.find((char)i) == m.end()) {
			cout << -1 << " ";
		}
		else {
			cout << m[(char)i] << " ";
		}
	}
}