#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];
int res[1001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	res[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (arr[i] <= dp[i - 1]) {
			int idx = i-1;
			int res_value = res[i-1];
			for (int j = 1; j <= i - 1; j++) {
				if (arr[i] <= dp[j]) {
					if (res_value < res[j]) {
						idx = j;
						res_value = res[j];
					}
				}
			}
			dp[i] = dp[idx]+ arr[i];
			res[i] = res[idx] + 1;
		}
		else {
			dp[i] = arr[i];
			res[i] = 1;
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		//cout << dp[i] << " ";
		max_value = max(max_value, res[i]);
	}
	//cout << "\n";
	/*for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
		max_value = max(max_value, res[i]);
	}
	cout << "\n";*/
	cout << max_value;
	return 0;
}