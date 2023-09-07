#include <iostream>
#include <climits>

using namespace std;

char arr[1001];
int dp[1001];

char dx[3] = { 'B', 'O', 'J' };
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string str;
	cin >> str;

	
	for (int i = 0; i < str.size(); i++) {
		arr[i + 1] = str[i];
	}

	for (int i = 0; i <= n; i++) {
		dp[i] = -1;
	}
	dp[1] = 0;

	int idx = 1;
	for (int i = 2; i <= n; i++) {
		char prev = ' ';
		if (arr[i] == 'B') {
			prev = 'J';
		}
		else if (arr[i] == 'O') {
			prev = 'B';
		}
		else if (arr[i] == 'J') {
			prev = 'O';
		}

		int min_value = INT_MAX;
		for (int j = 1; j <= i - 1; j++) {
			if (dp[j] == -1) { continue; }
			if (arr[j] == prev) {
				min_value = dp[j] + (i - j) * (i - j);
				if (dp[i] == -1) {
					dp[i] = min_value;
				}
				else {
					dp[i] = min(dp[i], min_value);
				}
			}
		}
		//cout << dp[i] << " ";
	}
	cout << dp[n] << "\n";
	return 0;
}