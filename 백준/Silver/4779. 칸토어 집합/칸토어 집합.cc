#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

string s;

void dfs(int x, int start) {
	int len = x / 3;
	if (len == 0) {
		return;
	}

	int a, b;
	int mid1 = len + start;
	int mid2 = len * 2 + start;
	for (int i = mid1; i < mid2; i++) {
		s[i] = ' ';
	}
	for (int i = 0; i < 3; i++) {
		dfs(len, start + (i * len));
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n) {
		int x = pow(3, n);
		s = "";
		for (int i = 0; i < x; i++) {
			s += '-';
		}
		int len = (x / 3);
		int start = len;
		int end = len * 2;
		for (int i = start; i < end; i++) {
			s[i] = ' ';
		}
		for (int i = 0; i < 3; i++) {
			dfs(len, i*len); // 0 9 18
		}
		cout << s << "\n";
	}
	return 0;
}