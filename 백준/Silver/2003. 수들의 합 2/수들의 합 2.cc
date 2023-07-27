#include <iostream>

using namespace std;

int n, m;
int arr[10001];
int dp[10001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (dp[i] - dp[j] == m) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}