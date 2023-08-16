#include <iostream>
#include <queue>

using namespace std;

int arr[5][5];
int res[5][5];
bool visited[5][5];
queue<pair<int, int>> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			if (arr[nx][ny] == -1) { continue; }
			if (visited[nx][ny] == 0) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				res[nx][ny] = res[x][y] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int qx, qy;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				qx = i;
				qy = j;
			}
		}
	}
	int x, y;
	cin >> x >> y;
	q.push({ x, y });
	bfs();
	if (visited[qx][qy] == 0) {
		cout << -1;
	}
	else {
		cout << res[qx][qy];
	}
	return 0;
}