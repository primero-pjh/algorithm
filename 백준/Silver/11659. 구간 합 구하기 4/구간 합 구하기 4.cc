// 2022-08-21
#include<iostream>
#include<stdio.h>
using namespace std;

int N; int M;
int v[100001] = { 0 };
int dp[100001] = { 0 };

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		int a;
		scanf("%d", &a);
		v[i] = a;
	}

	dp[1] = v[1];
	dp[2] = v[2] + v[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + v[i];
	}
	
	for (int i = 0; i < M; i++) {
		int a; int b;
		scanf("%d %d", &a, &b);
		int sum = dp[b]-dp[a-1];
		printf("%d\n", sum);
	}

	return 0;
}