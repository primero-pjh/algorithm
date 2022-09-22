//22.09.22
#include <stdio.h>
#include <algorithm>

using namespace std;

int dp[1000][3] = { 0 };
int red[1000] = { 0, };
int green[1000] = { 0, };
int blue[1000] = { 0, };

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &red[i], &green[i], &blue[i]);
	}

	dp[0][0] = red[0];
	dp[0][1] = green[0];
	dp[0][2] = blue[0];
	for (int i = 1; i < n; i++) {
		int a, b, c;
		a = red[i] + min(dp[i-1][1], dp[i-1][2]);
		b = green[i] + min(dp[i-1][0], dp[i-1][2]);
		c = blue[i] + min(dp[i-1][0], dp[i-1][1]);
		dp[i][0] = a;
		dp[i][1] = b;
		dp[i][2] = c;
	}
	int res = 0;
	res = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	printf("%d", res);
	return 0;
}