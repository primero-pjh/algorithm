#include <stdio.h>

using namespace std;

int main() {
	int n, k;
	int arr[100] = { 0, };
	int dp[10001] = { 0, };
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = dp[j] + dp[j - arr[i]];
		}
	}
	
	printf("%d", dp[k]);
	return 0;
}