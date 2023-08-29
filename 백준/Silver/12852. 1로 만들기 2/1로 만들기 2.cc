#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int n;
queue<int> q;
vector<int> arr[1000001];
bool visited[1000001];
int dp[1000001];
int min_value = 0;
map<int, vector<int>> graph;
void dfs(vector<int> v, int parent) {
	if (v.size() > min_value) {
		return;
	}
	if (!v.empty() && v[v.size() - 1] == 1 && v.size() == min_value) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		exit(0);
	}
	if (parent % 3 == 0) {
		v.push_back(parent / 3);
		dfs(v, parent / 3);
		v.pop_back();
	}
	if (parent % 2 == 0) {
		v.push_back(parent / 2);
		dfs(v, parent / 2);
		v.pop_back();
	}
	v.push_back(parent - 1);
	dfs(v, parent - 1);
	v.pop_back();
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dp[i] = 0;
			continue;
		}
		if (i % 3 == 0 && i % 2 == 0) {
			dp[i] = min(dp[i / 3] + 1, min(dp[i/2] + 1, dp[i - 1] + 1));
		} else if (i % 3 == 0) {
			dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
		} else if (i % 2 == 0) {
			dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}

	vector<int> v;
	min_value = dp[n];
	cout << dp[n] << "\n";
	cout << n << " ";
	dfs(v, n);
	return 0;
}