// 2023-05-24
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;

void find(int x, int y) {
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		if (i != x && i != y) {
			sum += v[i];
		}
	}
	if (sum == 100) {
		for (int i = 0; i < 9; i++) {
			if (i != x && i != y) {
				printf("%d\n", v[i]);
			}
		}
		exit(0);
	}
}
int main() {
	int dp[10] = { 0, };
	for (int i = 0; i < 9; i++) {
		int x;
		scanf("%d", &x);
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 9; j++) {
			find(i, j);
		}
	}

	return 0;
}