#include <iostream>
#include <map>

using namespace std;

map<string, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		m[str]++;
	}
	for (int i = 0; i < n - 1; i++) {
		string str;
		cin >> str;
		m[str]--;
		if (m[str] == 0) {
			m.erase(str);
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first;
	}

	return 0;
}