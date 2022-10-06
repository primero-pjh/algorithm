#include <stdio.h>
#include <algorithm>

using namespace std;
int arr[2][100001] = { 0, };
int dp[2][100001] = { 0, };
int main() {
	int n, k;
	scanf("%d", &n);
	int cnt = n;
	while (cnt > 0) {
		scanf("%d", &k);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < k; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		
		dp[0][1] = arr[1][0] + arr[0][1];
		dp[1][1] = arr[0][0] + arr[1][1];

		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < k; j++) {
				dp[0][j] = max(max(dp[0][j - 2], dp[1][j - 2]), dp[1][j - 1]) + arr[0][j];
				dp[1][j] = max(max(dp[0][j - 2], dp[1][j - 2]), dp[0][j - 1]) + arr[1][j];
			}
		}

		/*for (int i = 0; i < k; i++) {
			printf("%d ", dp[0][i]);
		}
		printf("\n");
		for (int i = 0; i < k; i++) {
			printf("%d ", dp[1][i]);
		}
		printf("\n");*/
		printf("%d\n", max(dp[0][k - 1], dp[1][k - 1]));
		cnt--;
	}
	
	return 0;
}