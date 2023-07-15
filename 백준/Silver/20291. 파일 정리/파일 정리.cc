#include <iostream>
#include <string>
#include <map>

using namespace std;
map<string, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		string name, ext;
		bool is_ext = false;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '.') {
				is_ext = true;
				continue;
			}
			if (is_ext) {
				ext += str[j];
			}
			else {
				name += str[j];
			}
		}
		m[ext]++;
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << " " << iter->second << "\n";
	}
	return 0;
}