#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
map<int, vector<string>> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		string str;
		cin >> a >> str;
		m[a].push_back(str);
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		for (int i = 0; i < iter->second.size(); i++) {
			cout << iter->first << " " << iter->second[i] << "\n";
		}
	}

	return 0;
}