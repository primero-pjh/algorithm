#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

char arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

int n, m, a = 0, b = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int top_x, int top_y, char type) {
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
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) { continue; }
			if (arr[nx][ny] != type) { continue; }
			if (visited[nx][ny] == 0 && arr[nx][ny] == type) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				int cnt = bfs(i, j, arr[i][j]);
				if (arr[i][j] == 'W') {
					a += (cnt * cnt);
				}
				else if (arr[i][j] == 'B') {
					b += (cnt * cnt);
				}
			}
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}