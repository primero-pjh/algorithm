#include <iostream>
#include <algorithm>

using namespace std;

int dp[4][100001];
int main() {
	int n;
	cin >> n;
	int item[4] = { 1, 2, 5, 7 };
	
	for (int i = 1; i <= n; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i < 4; i++) {
		int a = item[i];
		for (int j = 1; j <= n; j++) {
			if (j < a) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				if (j % a == 0) {
					dp[i][j] = (j / a);
				}
				else {
					dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - a]);
				}
			}
			
		}
	}

	/*for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout << dp[3][n];
	return 0;
}