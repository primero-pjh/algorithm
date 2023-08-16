#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> m;
vector<string> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	for (int i = 0; i < v.size(); i++) {
		string r_str = v[i];
		reverse(r_str.begin(), r_str.end());
		m[v[i]]++;
		m[r_str]++;
		if (m[v[i]] == 2) {
			cout << v[i].size() << " " << v[i][v[i].size() / 2] << "\n";
			exit(0);
		}
	}
		
	return 0;
}