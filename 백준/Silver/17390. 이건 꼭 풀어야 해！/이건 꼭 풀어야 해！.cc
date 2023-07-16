#include <iostream>
#include <algorithm>

using namespace std;

int arr[300001];
int dp[300001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1] + arr[i - 1];
	}

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		cout << dp[r] - dp[l - 1] << "\n";
	}
	return 0;
}