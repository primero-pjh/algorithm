#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1001] = { 0, };
int dp[1001] = { 0, };
int main() {
	int n;
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[1] = arr[1];
	for (int i = 1; i <= n; i++) {
		dp[i] = arr[1];
	}

	for (int i = 2; i <= n; i++) {
		int a = max(arr[i], dp[i]);
		for (int j = 1; j < i; j++) {
			int x = i - j;
			a = max(a, dp[x] + dp[j]);
		}
		dp[i] = max(dp[i], a);
		for (int j = i; j <= n; j++) {
			dp[j] = dp[i];
		}
	}

	printf("%d\n", dp[n]);
	/*for (int i = 1; i <= n; i++) {
		printf("%d ", dp[i]);
	}
	printf("\n");*/
	
	return 0;
}
