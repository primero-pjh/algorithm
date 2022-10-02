#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	int arr[17][2] = { 0, };
	int dp[17] = { 0, };
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i][0] + i - 1 > 15) {
			continue;
		}
		int m_v = 0;
		for (int j = 1; j < i; j++) {
			m_v = max(dp[j], m_v);
		}
		int res = max(m_v + arr[i][1], dp[arr[i][0] + i - 1]);
		dp[arr[i][0] + i - 1] = res;
		/*for (int j = 1; j <= n; j++) {
			printf("%d ", dp[j]);
		}
		printf("\n");*/
	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res = max(dp[i], res);
	}
	printf("%d\n", res);
	return 0;
}