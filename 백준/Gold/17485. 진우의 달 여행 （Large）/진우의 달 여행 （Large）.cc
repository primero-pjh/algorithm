#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int arr[1001][1001];
int dp[1001][1001][3];

int dx[3] = { -1, -1, -1 };
int dy[3] = { -1, 0, 1 };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 3; j++) {
			dp[1][i][j] = arr[1][i];
		}
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				for (int q = 0; q < 3; q++) {
					if (k == q) { continue; }
					int nx = i + dx[q];
					int ny = j + dy[q];
					if (nx <= 0 || ny <= 0 || nx > n || ny > m) { continue; }
					if (dp[i][j][k] != 0) {
						dp[i][j][k] = min(dp[i][j][k], dp[nx][ny][q] + arr[i][j]);
					}
					else {
						dp[i][j][k] = dp[nx][ny][q] + arr[i][j];
					}
				}
			}
		}
	}

	
	int ans = INT_MAX;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 3; j++) {
			ans = min(ans, dp[n][i][j]);
		}
	}
	cout << ans;
	return 0;
}