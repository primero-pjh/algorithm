#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
int arr[10] = { 0, };
int type[10];
set<string> s;
int n, m;

void dfs(int idx, vector<int> list) {
	if (list.size() == m) {
		string new_str = "";
		for (int i = 0; i < list.size(); i++) {
			new_str += to_string(list[i]);
			new_str += " ";
		}
		if (s.find(new_str) == s.end()) {
			s.insert(new_str);
			for (int i = 0; i < list.size(); i++) {
				cout << list[i] << " ";
			}
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) { continue; }
		list.push_back(arr[i]);
		type[i] = 1;
		dfs(i, list);
		list.pop_back();
		type[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	for (int i = 0; i < n; i++) {
		type[i] = 1;
		vector<int> v;
		v.push_back(arr[i]);
		dfs(i, v);
		type[i] = 0;
	}
	return 0;
}