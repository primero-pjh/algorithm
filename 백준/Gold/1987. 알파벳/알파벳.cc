#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int r, c;
char arr[21][21];
bool visited[26];
int res[21][21];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int max_value = 1;

void dfs(int x, int y, int cnt) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= r || ny >= c) { continue; }
		if (visited[arr[nx][ny] - 'A'] == 1) { continue; }
		visited[arr[nx][ny] - 'A'] = 1;
		max_value = max(max_value, cnt + 1);
		dfs(nx, ny, cnt + 1);
		visited[arr[nx][ny] - 'A'] = 0;
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}

	visited[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);

	cout << max_value;
	return 0;
}