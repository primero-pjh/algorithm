#include <iostream>
#include <map>

using namespace std;

int arr[6][6];
int res[6][6];
map<int, int[2]> graph;

int dx[5] = { 5,4,3,2,1 };
int dy[5] = { 1,2,3,4,5 };

int cnt = 0;
map<int, bool> row;
map<int, bool> column;
int a = 0, b = 0;
bool check(int x, int y) {
	// 가로체크
	int cnt1 = 0;
	for (int i = 1; i <= 5; i++) {
		if (res[x][i] == 1) {
			cnt1++;
		}
	}
	if (cnt1 == 5) {
		row[x] = 1;
	}
	// 세로체크
	int cnt2 = 0;
	for (int i = 1; i <= 5; i++) {
		if (res[i][y] == 1) {
			cnt2++;
		}
	}
	if (cnt2 == 5) {
		column[x] = 1;
	}
	// \ 체크
	int cnt3 = 0;
	if (x == y) {
		for (int i = 1; i <= 5; i++) {
			if (res[i][i] == 1) {
				cnt3++;
			}
		}
	}
	if (cnt3 == 5) {
		a = 1;
	}
	// / 체크
	int cnt4 = 0;
	for (int i = 0; i < 5; i++) {
		int b_x = dx[i];
		int b_y = dy[i];
		if (b_x == x && b_y == y) {
			for (int j = 1; j <= 5; j++) {
				if (res[j][6 - j] == 1) {
					cnt4++;
				}
			}
		}
	}
	if (cnt4 == 5) {
		b = 1;
	}

	//cout << row.size() << ", " << column.size() << ", " << a << ", " << b << "\n";
	if ((row.size() + column.size() + a + b) >= 3) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> arr[i][j];
			graph[arr[i][j]][0] = i;
			graph[arr[i][j]][1] = j;
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int a;
			cin >> a;
			int x = graph[a][0];
			int y = graph[a][1];
			res[x][y] = 1;
			if (check(x, y)) {
				cout << (i - 1) * 5 + j << "\n";
				exit(0);
			}
		}
	}
	return 0;
}