#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[13];
int dp[10001];
vector<pair<int, int>> graph[10001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, d;
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[b].push_back({ a, c });
	}
	for (int i = 0; i <= d; i++) {
		dp[i] = -1;
	}

	dp[0] = 0;
	for (int i = 1; i <= d; i++) {
		dp[i] = dp[i - 1] + 1;
		if (graph[i].size() > 0) {
			for (int j = 0; j < graph[i].size(); j++) {
				pair<int, int> child = graph[i][j];
				dp[i] = min(dp[i], dp[child.first] + child.second);
			}
		}
	}
	cout << dp[d];
	return 0;
}