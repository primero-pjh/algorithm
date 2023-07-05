#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10] = { 0, };
int n, m;
void dfs(int start_idx, vector<int> v) {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i, v);
		v.pop_back();
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> v;
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		v.push_back(arr[i]);
		dfs(i, v);
		v.pop_back();
	}
	return 0;
}