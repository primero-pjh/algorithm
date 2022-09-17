// 2021-11-28
#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long dp[101][101] = { 0 };

int main() {
	int n;
	cin >> n;

	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[1][3] = 1;
	dp[1][4] = 1;
	dp[1][5] = 1;
	dp[1][6] = 1;
	dp[1][7] = 1;
	dp[1][8] = 1;
	dp[1][9] = 1;


	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][0] = (dp[i-1][1]) % 1000000000;
			}
			else if (j == 9) {
				dp[i][9] = (dp[i-1][8]) % 1000000000;
			}
			else {
				dp[i][j] = (dp[i - 1][j+1] + dp[i-1][j-1]) % 1000000000;
			}
		}
	}
	
	unsigned long long sum = 0;
	
	for (int j = 0; j< 10; j++) {
		sum = (sum + dp[n][j]) % 1000000000;
	}
	
	cout << sum << endl;
	
	return 0;
}