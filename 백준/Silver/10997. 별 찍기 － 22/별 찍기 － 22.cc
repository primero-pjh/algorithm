// 2022-08-20
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

vector<vector<char>> v;
int a = 0;
int b = 0;
void dfs(int count, bool is_vertical, bool is_minus) {
	if (is_vertical == false && is_minus == true) {
		for (int i = 0; i < count; i++) {
			v[a][b--] = ' ';
		}
		b++;
	} else if (is_vertical == true && is_minus == false) {
		for (int i = 0; i < count; i++) {
			v[a++][b] = ' ';
			
		}
		a--;
	}
	else if (is_vertical == false && is_minus == false) {
		for (int i = 0; i < count; i++) {
			v[a][b++] = ' ';
		}
		b--;
	}
	else if (is_vertical == true && is_minus == true) {
		for (int i = 0; i < count; i++) {
			v[a--][b] = ' ';
			
		}
		a++;
	}
}

int main() {
	int N;
	scanf("%d", &N);
	if (N == 1) {
		printf("*");
		return 0;
	}
	int x; int y;
	y = 4 * N - 3;
	x = 4 * N - 1;
	int cnt = 4 * (N - 1);
	for (int i = 0; i < x; i++) {
		vector<char> a;
		for (int j = 0; j < y; j++) {
			a.push_back('*');
		}
		v.push_back(a);
	}

	a = 1;
	b = y - 1;
	int add = 1;
	for (int i = 0; i < cnt; i++) {
		if (i < 2) {
			if (i == 0) {
				dfs(cnt, false, true);
			}
			else if (i == 1) {
				dfs(cnt+1, true, false);
			}
		}
		else {
			if (i % 4 == 0) {
				dfs(cnt-add, false, true);
			} else if (i % 4 == 1) {
				dfs(cnt - add, true, false);
				add += 2;
			}
			else if (i % 4 == 2) {
				dfs(cnt-add, false, false);
			}
			else if (i % 4 == 3) {
				dfs(cnt- add, true, true);
				add += 2;
			}
		}
	}

	for (int i = 0; i < x; i++) {
		if (i == 1) {
			printf("*");
		}
		else {
			for (int j = 0; j < y; j++) {
				printf("%c", v[i][j]);
			}
		}
		
		printf("\n");
	}
	return 0;
}