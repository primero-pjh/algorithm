#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string str;
	int arr[1001];
	map<int, set<string>> m;
	for (int i = 0; i < n; i++) {
		cin >> str;
		m[str.size()].insert(str);
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		for (auto it = iter->second.begin(); it != iter->second.end(); it++) {
			cout << *it << "\n";
		}
	}


	return 0;
}