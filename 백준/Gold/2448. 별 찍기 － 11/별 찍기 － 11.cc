#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int n;
int a;
vector<vector<char>> v;

void dfs(int x, int y, int count, int q, bool state, int cnt) {
	if (state == true) {
		int y1, y2;
		y1 = y + count; 
		y2 = y - count;
		for (int i = x; i < x + count; i++) {
			for (int j = y - count + 1; j < y + count; j++) {
				if (j > y2 && j < y1) {
					v[i][j] = ' ';
				}
			}
			y1--;
			y2++;
		}
	}
	else {
		if (count == 3) {
			for (int i = x; i < x + count; i++) {
				for (int j = y - count + 1; j < y + count; j++) {
					if (i == x) {
						if (i == x && j == y) {

						}
						else {
							v[i][j] = ' ';
						}
					}
					else if (i == x + 1) {
						if (j == y) {
							v[i][j] = ' ';
						}
					}
				}
			}
			return;
		}
		else {
			for (int i = x; i < x + count; i++) {
				for (int j = y - count + 1; j < y + count; j++) {
					if (i % (count / 2) == 0 && j % (count / 2) == ((count / 2) - 1)) {
						if (v[i][j] == '*') {
							//printf("i: %d, j: %d, count: %d, cnt: %d\n", i, j, count, cnt);
							//if (cnt == 3) {
							if(i == x+(count/2) && j == y) {
								dfs(i, j, (count / 2), (q / 2), true, 1);
							}
							else {
								dfs(i, j, (count / 2), (q / 2), false, 1);
							}
							cnt++;
						}
					}
				}
			}
		}
		
	}
	
}

int main() {
	scanf("%d", &n);
	if (n == 3) {
		printf("  *  \n");
		printf(" * * \n");
		printf("*****\n");
		return 0;
	}
	a = 2 * n - 1;
	int y1, y2;
	y1 = a / 2; y2 = a / 2;
	for (int i = 0; i < n; i++) {
		vector<char> vec;
		for (int j = 0; j < a; j++) {
			if (j >= y1 && j <= y2) {
				vec.push_back('*');
			}
			else {
				vec.push_back(' ');
			}
		}
		y2++;
		y1--;
		v.push_back(vec);
	}

	y1 = (a / 2) - (n / 2);
	y2 = (a / 2) + (n / 2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			if (i >= (n/2) && j > y1 && j < y2) {
				v[i][j] = ' ';
			}
		}
		if (i >= (n / 2)) {
			y1++;
			y2--;
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			if (i % (n/2) == 0 && j % (n/2) == ((n/2)-1)) {
				
				if (v[i][j] == '*') {
					//printf("origin] i: %d, j: %d, cnt: %d\n", i, j, cnt);

					/*if (cnt % 3 == 0) {
						dfs(i, j, (n / 2), (a / 2), true, 1);
					}
					else {*/
						dfs(i, j, (n / 2), (a / 2), false, 1);
					//}
					cnt++;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
}