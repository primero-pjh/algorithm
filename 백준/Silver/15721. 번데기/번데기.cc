//2023.07.03
#include <iostream>
#include <map>

using namespace std;

map<int, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, t, type;
	cin >> a;
	cin >> t;
	cin >> type;

	/* 0 1 0 1 0 0 1 1*/
	/* 0 1 0 1 0 0 1 1*/
	m[0] = 0;
	m[1] = 0;
	int idx = 0;
	int len = 2;
	while (1) {
		int current = 0;
		int i = 0;
		for (i = idx; i < idx + 4; i++) {
			m[current % 2]++;
			if (m[type] == t) {
				cout << i % a << "\n";
				return 0;
			}
			current++;
		}
		idx = i;
		current = 0;
		for (i = idx; i < idx + len; i++) {
			m[current]++;
			if (m[type] == t) {
				cout << i % a << "\n";
				return 0;
			}
		}
		current = 1;
		idx = i;
		for (i = idx; i < idx + len; i++) {
			m[current]++;
			if (m[type] == t) {
				cout << i % a << "\n";
				return 0;
			}
		}
		idx = i;
		len++;
	}

	/*
	뻔 데 뻔 데 뻔 뻔 데 데 뻔 데 뻔 데
	*/

	return 0;
}