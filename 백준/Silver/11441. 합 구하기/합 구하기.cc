#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		dp[i] = dp[i - 1] + arr[i];
	}

	/*for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	cout << "\n";*/
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << "\n";
	}
	return 0;
}