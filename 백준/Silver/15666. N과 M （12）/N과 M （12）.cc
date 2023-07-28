#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
set<string> s;
void dfs(vector<int> v, int idx) {
	if (v.size() == m) {
		string str = "";
		for (int i = 0; i < v.size(); i++) {
			str += to_string(v[i]) + " ";
		}
		if (s.find(str) != s.end()) {
			return;
		}
		else {
			s.insert(str);
			cout << str << "\n";
		}
		return;
	}
	for (int i = idx; i < n; i++) {
		v.push_back(arr[i]);
		dfs(v, i);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> v;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		dfs(v, i);
		v.pop_back();
	}
	return 0;
}