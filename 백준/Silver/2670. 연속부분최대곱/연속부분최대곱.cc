#include <iostream>

using namespace std;

double arr[10001];
double dp[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	double max_value = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (j == i) {
				dp[j] = arr[j];
			}
			else {
				dp[j] = dp[j - 1] * arr[j];
			}
			max_value = max(max_value, dp[j]);
		}
	}

	cout << fixed;
	cout.precision(3);
	cout << max_value << "\n";
	return 0;
}