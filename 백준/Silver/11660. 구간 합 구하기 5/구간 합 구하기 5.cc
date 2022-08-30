//2022-08-30
#include<stdio.h>

using namespace std;

int arr[1025][1025] = { 0, };
int dp[1025][1025] = { 0, };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int a;
			scanf("%d", &a);
			arr[i][j] = a;
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == 1) {
				dp[i][j] = arr[i][j] + dp[i][j-1];
			}
			else if (j == 1) {
				dp[i][j] = dp[i-1][j] + arr[i][j];
			}
			else {
				dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - (dp[i - 1][j - 1]) + arr[i][j];
			}
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int a = x2-x1+1;
		
		int b = y2-y1+1;
		int x = dp[x2][y2 - b];
		int y = dp[x2-a][y2];
		int z = dp[x1-1][y1-1];
		int res = dp[x2][y2] - (x + y - z);
		printf("%d\n", res);
	} 

	
}