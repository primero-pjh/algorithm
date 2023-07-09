#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;


unsigned long long dp[101] = { 0, };
pair<int, int> arr[101];

unsigned long long res = INT_MAX;
int n;
int k;

void dfs(int idx) {
	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MAX - 1;
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i + 1] = dp[i] + arr[i].first > dp[i + 1] ? dp[i + 1] : dp[i] + arr[i].first;
		// 큰점프
		dp[i + 2] = dp[i] + arr[i].second > dp[i + 2] ? dp[i + 2] : dp[i] + arr[i].second;
		// 매우 큰 점프
		if (idx == i) {
			dp[i + 3] = dp[i] + k > dp[i + 3] ? dp[i + 3] : dp[i] + k;
		}
	}

	res = min(res, dp[n]);
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		pair<int, int> p;
		int a, b;
		cin >> a >> b;
		p.first = a;
		p.second = b;
		arr[i] = p;
	}
	cin >> k;
	
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	
	cout << res << "\n";
	return 0;
}