#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[250][250];
bool visited[250][250];
queue<pair<int, int>> q;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1};
int ans = 0;

void bfs(int top_x, int top_y) {
	q.push({ top_x, top_y });
	visited[top_x][top_y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] == 0) { continue; }
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (visited[nx][ny] == 0 && arr[nx][ny] == 1) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && arr[i][j] == 1) {
				bfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	
	return 0;
}