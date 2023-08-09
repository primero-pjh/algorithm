#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
char arr[8][8];
vector<pair<int, int>> v;
int min_value = 0;
void left(char temp[8][8], int x, int y) {
	y--;
	if (x < 0 || y < 0 || x >= n || y >= m) { return; }
	if (arr[x][y] == '6') { return; }
	temp[x][y] = '#';
	left(temp, x, y);
}
void right(char temp[8][8], int x, int y) {
	y++;
	if (x < 0 || y < 0 || x >= n || y >= m) { return; }
	if (arr[x][y] == '6') { return; }
	temp[x][y] = '#';
	right(temp, x, y);
}
void up(char temp[8][8], int x, int y) {
	x--;
	if (x < 0 || y < 0 || x >= n || y >= m) { return; }
	if (arr[x][y] == '6') { return; }
	temp[x][y] = '#';
	up(temp, x, y);
}
void down(char temp[8][8], int x, int y) {
	x++;
	if (x < 0 || y < 0 || x >= n || y >= m) { return; }
	if (arr[x][y] == '6') { return; }
	temp[x][y] = '#';
	down(temp, x, y);
}

void dfs(char temp[8][8], int idx) {
	if (idx >= v.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (temp[i][j] == '0') {
					cnt++;
				}
			}
		}
		min_value = min(min_value, cnt);
		return;
	}

	char type = arr[v[idx].first][v[idx].second];
	char test[8][8];
	copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
	if (type == '1') {
		left(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		right(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		up(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		down(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
	}
	else if (type == '2') {
		left(test, v[idx].first, v[idx].second);
		right(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		up(test, v[idx].first, v[idx].second);
		down(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
	}
	else if (type == '3') {
		up(test, v[idx].first, v[idx].second);
		right(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		right(test, v[idx].first, v[idx].second);
		down(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		down(test, v[idx].first, v[idx].second);
		left(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		left(test, v[idx].first, v[idx].second);
		up(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
	}
	else if (type == '4') {
		up(test, v[idx].first, v[idx].second);
		right(test, v[idx].first, v[idx].second);
		left(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		up(test, v[idx].first, v[idx].second);
		right(test, v[idx].first, v[idx].second);
		down(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		down(test, v[idx].first, v[idx].second);
		left(test, v[idx].first, v[idx].second);
		right(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
		left(test, v[idx].first, v[idx].second);
		up(test, v[idx].first, v[idx].second);
		down(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
		copy(&temp[0][0], &temp[0][0] + 8 * 8, &test[0][0]);
	}
	else if (type == '5') {
		up(test, v[idx].first, v[idx].second);
		right(test, v[idx].first, v[idx].second);
		left(test, v[idx].first, v[idx].second);
		down(test, v[idx].first, v[idx].second);
		dfs(test, idx + 1);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= '1' && arr[i][j] <= '5') {
				v.push_back({ i, j });
			}
		}
	}

	min_value = n * m;
	
	int idx = 0;
	char temp[8][8];
	copy(&arr[0][0], &arr[0][0] + 8 * 8, &temp[0][0]);
	dfs(temp, 0);
	
	cout << min_value << "\n";
	return 0;
}