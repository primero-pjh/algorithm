#include <stdio.h>
#include<string>
#include<iostream>
#include<algorithm>


using namespace std;

int dp[1001][1001] = { 0, };

int main() {
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;

	if (str1.size() > str2.size()) {
		if (str1.size() != str2.size()) {
			while (str1.size() != str2.size()) {
				str2 += '-';
			}
		}
	}
	else {
		if (str2.size() != str1.size()) {
			while (str1.size() != str2.size()) {
				str1 += '-';
			}
		}
	}
	
	
	int n = str1.size();
	int m_v = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int m = 0;
			if (str1[j - 1] == str2[i - 1]) {
				dp[i][j] = dp[i-1][j - 1] + 1;
			}
			else {
				m = max(dp[i][j - 1], dp[i - 1][j]);
				dp[i][j] = m;
			}
			m_v = max(dp[i][j], m_v);
		}
	}

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}*/
	printf("%d", m_v);
}