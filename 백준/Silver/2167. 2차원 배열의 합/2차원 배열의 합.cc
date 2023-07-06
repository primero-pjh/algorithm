#include <iostream>

using namespace std;

int arr[301][301] = { 0, };
int dp[301][301] = { 0, };
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] += dp[i][j - 1] + arr[i][j];
		}
	}

	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int res = 0;
		
		int a = i > x ? i : x;
		int b = i > x ? x : i;
		int c = j > y ? j : y;
		int d = j > y ? y : j;

		int sum1 = 0;
		int sum2 = 0;
		for (int idx = b; idx <= a; idx++) {
			sum1 += dp[idx][c];
			sum2 += dp[idx][d - 1];
		}
		res = sum1 - sum2;
		cout << res << "\n";
	}

	return 0;
}