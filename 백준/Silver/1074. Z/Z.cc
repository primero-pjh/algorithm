// 2022-08-20
#include<iostream>
#include<stdio.h>
using namespace std;

int N; int r; int c;
int res = 0;
void dfs(int x, int y, int cnt) {
	// 1사분면
	//printf("x, y: [%d, %d]\n", x, y);
	if (x == r && y == c) {
		printf("%d\n", res);
		exit(0);
		return;
	}
	//printf("??: [%d, %d]\n", x+(cnt/2), y+(cnt/2));
	if (r < x + (cnt) && r >= x && c < y + (cnt) && c >= y) {
		//1
		dfs(x, y, cnt / 2);
		//2
		dfs(x, y+(cnt/2), cnt / 2);
		//3
		dfs(x+(cnt/2), y, cnt / 2);
		//4
		dfs(x + (cnt / 2), y + (cnt / 2), cnt / 2);
	}
	else {
		res += (cnt * cnt);
	}
	
}

int main() {
	scanf("%d %d %d", &N, &r, &c);
	int count = 1 << N;
	dfs(0, 0, count);
	return 0;
}