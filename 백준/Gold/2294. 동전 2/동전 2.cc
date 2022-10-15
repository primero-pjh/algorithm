#include <stdio.h>
#include <algorithm>
#include<limits.h>

using namespace std;

int arr[101] = { 0, };
int dp[101][10001] = { 0, };
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr + n+1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i != 1) {
				dp[i][j] = dp[i - 1][j];
			}
			if (j % arr[i] == 0) {
				dp[i][j] = j / arr[i];
			}
		}
	}

	for (int i = 2; i <= k; i++) {
		int m_v = 0;
		if (dp[n][i] == 0) {
			m_v = INT_MAX;
		}
		else {
			m_v = dp[n][i];
		}
		
		int a = 1;
		int b = i - 1;
		while (a<=b) {
			if (dp[n][a] != 0 && dp[n][b] != 0) {
				m_v = min(m_v, (dp[n][a] + dp[n][b]));
				dp[n][i] = m_v;
			}
			a++;
			b--;
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	
	if (dp[n][k] == 0) {
		printf("%d\n", -1);
	}
	else {
		printf("%d", dp[n][k]);
	}
	return 0;
}