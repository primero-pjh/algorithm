#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int main() {
	int n;
	scanf("%d", &n);
	int arr[1001] = { 0, };
	int dp[1001] = { 0, };
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		int sum = 1;
		int idx = 0;
		for (int j = 1; j <= i; j++) {
			if (arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	int m_v = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] > m_v) {
			m_v = dp[i];
		}
	}
	printf("%d ", m_v);
	return 0;
}