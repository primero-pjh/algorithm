// 2023-05-24
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int n, m;
int home_idx = 0;
int chi_idx = 0;
int home[100][2];
int chi[100][2];
vector<int> res;
void calc(vector<int> v) {
	int x, y;
	int sum = 0;
	for (int i = 0; i < home_idx; i++) {
		int distance = 100;
		for (int j = 0; j < v.size(); j++) {
			x = abs(home[i][0] - chi[v[j]][0]);
			y = abs(home[i][1] - chi[v[j]][1]);
			distance = distance > (x + y) ? (x + y) : distance;
		}
		sum += distance;
	}
	res.push_back(sum);
}
void dfs(int len, vector<int> v) {
	if (v.size() != m) {
		len++;
		for (int i = len; i < chi_idx; i++) {
			v.push_back(i);
			dfs(i, v);
			v.pop_back();
		}
	}
	else {
		calc(v);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	int x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &x);
			if (x == 1) {
				home[home_idx][0] = i;
				home[home_idx][1] = j;
				home_idx++;
			}
			else if (x == 2) {
				chi[chi_idx][0] = i;
				chi[chi_idx][1] = j;
				chi_idx++;
			}
		}
	}
	
	int sum = 0;
	
	for (int i = 0; i < chi_idx; i++) {
		vector<int> v;
		v.push_back(i);
		dfs(i, v);
	}
	int min = res[0];
	for (int i = 0; i < res.size(); i++) {
		min = min > res[i] ? res[i] : min;
	}
	printf("%d\n", min);
	return 0;
}