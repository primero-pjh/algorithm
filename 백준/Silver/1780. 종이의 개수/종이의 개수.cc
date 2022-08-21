// 2022-08-21
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
using namespace std;

int N; int r; int c;
int a_res = 0;		// -1 개수
int b_res = 0;		// 0 개수
int c_res = 0;		// 1 개수

//vector<vector<int>> v;
int v[2200][2200] = { 0 };

bool check_func(int x, int y, int cnt) {
	int check = v[x][y];
	for (int i = x; i < cnt + x; i++) {
		for (int j = y; j < cnt + y; j++) {
			if (check != v[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int x, int y, int cnt) {
	if (check_func(x, y, cnt) == true) {
		if (v[x][y] == -1) { a_res++; }
		else if (v[x][y] == 0) { b_res++; }
		else if (v[x][y] == 1) { c_res++; }
		return;
	}
	else {
		for (int i = x; i < cnt+x; i++) {
			for (int j = y; j < cnt+y; j++) {
				if (cnt == 3) {
					if (v[i][j] == -1) {
						a_res++;
					}
					else if (v[i][j] == 0) {
						b_res++;
					}
					else if (v[i][j] == 1) {
						c_res++;
					}
				}
				else {
					if (i % (cnt/3) == 0 && j % (cnt/3) == 0) {
						dfs(i, j, cnt / 3);
					}
				}
			}
		}
	}

	
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int b = 0;
		for (int j = 0; j < N; j++) {
			scanf("%d", &b);
			v[i][j] = b;
		}
	}
	dfs(0, 0, N);

	printf("%d\n%d\n%d\n", a_res, b_res, c_res);
	return 0;
}