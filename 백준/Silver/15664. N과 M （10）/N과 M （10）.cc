#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector<int> v;
int n, m;
int arr[10];
set<string> graph;
void dfs(int idx, vector<int> v) {
	if (v.size() == m) {
		string str = "";
		for (int i = 0; i < v.size(); i++) {
			str += to_string(v[i]);
			if (i != v.size() - 1) {
				str += " ";
			}
		}
		if (graph.find(str) == graph.end()) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}
		graph.insert(str);
		return;
	}
	for (int i = idx; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i + 1, v);
		v.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		vector<int> v;
		v.push_back(arr[i]);
		dfs(i+1, v);
	}

	return 0;
}