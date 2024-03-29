#include <iostream>

using namespace std;

int arr[1025][1025];
int dp[1025][1025];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j-1] + arr[i][j];
			dp[i][j] = dp[i][j] - (dp[i - 1][j - 1]);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int a, b, c, d;
		a = dp[x2][y2];
		b = dp[x1-1][y2];
		c = dp[x2][y1-1];
		d = dp[x1-1][y1-1];
		cout << a - (b + c) + d << "\n";
	}

	return 0;
}