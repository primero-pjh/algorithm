#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char arr[51][51];
int res[51][51];
bool visited[51][51];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
int n, m;
int max_value = 0;

void reset() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			res[i][j] = 0;
		}
	}
}
void bfs(int a, int b) {
	reset();
	visited[a][b] = 1;
	q.push({ a, b });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (arr[nx][ny] == 'W') { continue; }
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				res[nx][ny] = res[x][y] + 1;
				max_value = max(res[nx][ny], max_value);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}
	cout << max_value;
	return 0;
}