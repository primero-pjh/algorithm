#include <iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int arr[15] = { 0, };
	int x, y;
	int res_x = n;
	int cnt_x = 0;
	int cnt_y = 0;
	
	for (int i = 0; i < 14; i++) {
		cin >> arr[i];
	}

	
	for (int i = 0; i < 14; i++) {
		if (res_x >= arr[i]) {
			int a = (res_x / arr[i]);
			res_x -= (a * arr[i]);
			cnt_x += a;
		}
	}

	int dp[15] = { 0, };
	int prev = arr[0];
	dp[0] = 0;
	for (int i = 1; i < 14; i++) {
		if (arr[i] > prev) {
			if (dp[i - 1] < 0) {
				dp[i] = 2;
			}
			else {
				dp[i] = dp[i - 1] + 1;
			}
		}
		else if (arr[i] == prev) {
			dp[i] = dp[i-1];
		}
		else if (arr[i] < prev) {
			if (dp[i - 1] > 0) {
				dp[i] = -2;
			}
			else {
				dp[i] = dp[i - 1] - 1;
			}
		}
		prev = arr[i];
	}

	int res_y = n;
	int cnt = 0;
	for (int i = 0; i < 14; i++) {
		// 매도
		if (dp[i] >= 4) {
			res_y = res_y + (arr[i] * cnt);
			cnt = 0;
		}
		// 매수
		else if (dp[i] <= -4) {
			int a = (res_y / arr[i]);
			res_y = res_y - (arr[i] * a);
			cnt += a;
		}
	}

	if ((arr[13] * cnt_x + res_x) > (arr[13] * cnt + res_y)) {
		cout << "BNP";
	}
	else if ((arr[13] * cnt_x + res_x) == (arr[13] * cnt + res_y)) {
		cout << "SAMESAME";
	}
	else if ((arr[13] * cnt_x + res_x) < (arr[13] * cnt + res_y)) {
		cout << "TIMING";
	}
	return 0;
}