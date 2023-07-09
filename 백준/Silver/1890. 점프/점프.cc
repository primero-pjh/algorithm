#include <iostream>

using namespace std;

int arr[101][101] = { 0, };
unsigned long long dp[101][101] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0) {
				continue;
			}
			if (i == n - 1 && j == n - 1) {
				continue;
			}
			//right
			if (j+arr[i][j] < n) {
				dp[i][j + arr[i][j]] += (dp[i][j]);
			}
			//bottom
			if (i + arr[i][j] < n) {
				dp[i + arr[i][j]][j] += (dp[i][j]);
			}
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << dp[n - 1][n - 1] << "\n";
	return 0;
}