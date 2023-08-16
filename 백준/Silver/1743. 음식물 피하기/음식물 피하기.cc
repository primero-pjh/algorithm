#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
char arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int max_value = 0;

void reset_visited() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visited[i][j] = 0;
		}
	}
}
int bfs(int top_x, int top_y) {
	q.push({ top_x, top_y });
	visited[top_x][top_y] = 1;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] == '.') { continue; }
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) { continue; }
			if (visited[nx][ny] == 0 && arr[nx][ny] == '#') {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			arr[i][j] = '.';
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = '#';
	}

	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visited[i][j] == 0 && arr[i][j] == '#') {
				int cnt = bfs(i, j);
				max_value = max(max_value, cnt);
			}
		}
	}
	cout << max_value;
	
	return 0;
}