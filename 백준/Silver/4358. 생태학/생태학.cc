#include <iostream>
#include <string>
#include <map>
#include <stdio.h>

using namespace std;
map<string, int> m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int sum = 0;
	string str;
	while (getline(cin, str)) {
		if (m.find(str) == m.end()) {
			m[str] = 0;
		}
		if (m.find(str) != m.end()) {
			m[str]++;
		}
		sum++;
	}

	cout << fixed;
	cout.precision(4);
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		string tree = iter->first;
		double avg = (iter->second / (double)sum) * 100;
		cout << tree << " " << avg << "\n";
	}

	return 0;
}