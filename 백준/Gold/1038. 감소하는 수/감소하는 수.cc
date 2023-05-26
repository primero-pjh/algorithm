#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int n;
int dp[11][11];
int idx = 0;

void dfs(int len, string str) {
	if (str[str.size() - 1] >= str[str.size() - 2]) {
		return;
	}
	//cout << "test: " << str << endl;
	if (len == 0) {
		idx++;
	}
	if (idx == n) {
		cout << str << "\n";
		exit(0);
	}
	int y = str[str.size() - 1] - '0';
	//printf("%d\n", y);
	for (int i = 0; i < y; i++) {
		str += (i + '0');
		dfs(len - 1, str);
		str.pop_back();
	}
}

void start(int x, int y) {
	// y로 시작하는 x+1 자리수
	//printf("%d %d\n", x, y);
	string str = "";
	str += (y + '0');
	for (int j = 0; j < y; j++) {
		str += (j + '0');
		dfs(x-1, str);
		str.pop_back();
	}
}

int main() {
	scanf("%d", &n);
	if (n <= 10) {
		printf("%d\n", n);
		return 0;
	}
	for (int i = 0; i < 10; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j-1];
		}
	}
	dp[0][0] = 0;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			sum += dp[i][j];
			if (sum >= n) {
				idx = (sum - dp[i][j]);
				start(i, j);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}