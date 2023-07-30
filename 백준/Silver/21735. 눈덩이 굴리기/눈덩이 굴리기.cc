#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int arr[101];
int max_value = 0;
void dfs(vector<int> temp, int idx, int sum) {
	if (temp.size() == m || idx >= n) {
		max_value = max(max_value, sum);
		return;
	}

	if (idx + 1 > n) {
		return;
	}
	temp.push_back(idx + 1);
	dfs(temp, idx + 1, sum + arr[idx + 1]);
	temp.pop_back();
	if (idx + 2 > n) {
		return;
	}
	temp.push_back(idx + 2);
	dfs(temp, idx + 2, (sum / 2) + arr[idx + 2]);
	temp.pop_back();
	return;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	vector<int> temp;
	int sum = 1;
	temp.push_back(1);
	dfs(temp, 1, sum + (arr[1]));
	temp.pop_back();
	if (n >= 2) {
		temp.push_back(2);
		dfs(temp, 2, (sum / 2) + arr[2]);
	}
	cout << max_value;
	return 0;
}