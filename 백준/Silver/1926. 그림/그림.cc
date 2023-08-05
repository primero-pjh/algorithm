#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[501][501];
bool visited[501][501];
int res[501][501];
int max_value = 0;
queue<pair<int, int>> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;
void bfs(pair<int, int> top, int cnt) {
	q.push({ top.first, top.second });
	cnt++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (arr[nx][ny] == 0) { continue; }
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				res[nx][ny] = res[x][y] + 1;
				cnt++;
			}
		}
	}
	max_value = max(max_value, cnt);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				bfs(pair<int, int> (i, j), 0);
				ans++;
			}
		}
	}

	cout << ans << "\n";
	cout << max_value << "\n";
	return 0;
}