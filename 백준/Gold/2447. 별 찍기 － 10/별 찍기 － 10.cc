#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int cnt = 0;
vector<vector<char>> v;

void dfs(int x, int y, int count, bool state) {
	if (count < 3) {
		return;
	}
	if (state == false) {
		for (int i = x; i < count+x; i++) {
			for (int j = y; j < count+y; j++) {
				v[i][j] = ' ';
			}
		}
	}
	else {
		int zero_cnt = 0;
		for (int i = x; i < count+x; i++) {
			for (int j = y; j < count+y; j++) {
				if (i % (count/3) == 0 && j % (count/3) == 0) {
					zero_cnt++;
					if (zero_cnt == 5) {
						dfs(i, j, count / 3, false);
					}
					else {
						dfs(i, j, count / 3, true);
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; i++) {
		vector<char> a;
		for (int j = 0; j < cnt; j++) {
			if (i % 3 == 1 && j % 3 == 1) {
				a.push_back(' ');
			}
			else {
				a.push_back('*');
			}
		}
		v.push_back(a);
	}
	
	int zero_cnt = 0;
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (i % (cnt/3) == 0 && j % (cnt/3) == 0) {
				zero_cnt++;
				if (zero_cnt == 5) {
					dfs(i, j, cnt / 3, false);
				}
				else {
					dfs(i, j, cnt / 3, true);
				}
			}
		}
	}

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
}
