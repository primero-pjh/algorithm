//2022-08-18
#include<iostream>
#include<cmath>
#include<algorithm>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int fib_count = 0;
int dp[50] = { 0, };

int fib(int n) {
	fib_count++;
	if (dp[n] > 0) {
		return dp[n];
	}
	if (n == 1 || n == 2) {
		dp[n] = 1;
		return 1;
	}
	else {
		dp[n] = fib(n - 1) + fib(n - 2);
		return dp[n];
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);
	
	int sum = 0;
	fib(n);
	
	printf("%d ", dp[n]);
	printf("%d", n-2);

	return 0;
}