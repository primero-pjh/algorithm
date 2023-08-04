#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll arr[1000002];
ll dp[1000002];
ll max_value = 0;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[b + 1] = a;
	}

	for (int i = 1; i <= 1000001; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	for (int i = 1; i <= 1000001; i++) {
		int a = i - k - 1;
		int b = i + k;
		if (a < 0) { a = 0; }
		if (b > 1000001) { b = 1000001; }
		ll value = 0;
		value = (dp[i] - dp[a]) + (dp[b] - dp[i]);
		max_value = max(max_value, value);
	}
	cout << max_value;

	return 0;
}