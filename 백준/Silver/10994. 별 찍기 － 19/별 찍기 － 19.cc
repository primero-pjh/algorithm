// 2022-08-19
#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> v;
int cnt = 0;

void dfs(int x, int y, int count) {
	if (x > cnt/2) {
		return;
	}
	for (int i = x; i < count; i++) {
		for (int j = y; j < count; j++) {
			if (count % 2 == 1) {
				v[i][j] = '*';
			}
			else {
				v[i][j] = ' ';
			}
		}
	}
	dfs(x+1, y+1, count - 1);
}

int main() {
	int n = 0;
	scanf("%d", &n);
	cnt = 4 * n - 3;
	if (n == 1) {
		printf("*");
		return 0;
	}
	for (int i = 0; i < cnt; i++) {
		vector<char> a;
		for (int j = 0; j < cnt; j++) {
			a.push_back('*');
		}
		v.push_back(a);
	}
	dfs(0, 0, cnt);

	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			printf("%c", v[i][j]);
		}
		printf("\n");
	}
	return 0;
}