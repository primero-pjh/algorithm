#include <iostream>

using namespace std;

int r, c, q;
int arr[1001][1001];
int dp[1001][1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> r >> c >> q;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	/*for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	int r1, c1, r2, c2;
	for (int i = 0; i < q; i++) {
		cin >> r1 >> c1 >> r2 >> c2;
		int sum = dp[r2][c2] - (dp[r2][c1 - 1] + dp[r1-1][c2]) + (dp[r1 - 1][c1 - 1]);
		int cnt = (r2 - r1 + 1) * (c2 - c1 + 1);
		cout << sum / cnt << "\n";
	}
	
}