#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int arr[301][301];
bool visited[301][301];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;
int n, m;

int ans = 0;
void bfs(int len) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != 0) {
				q.push({ i , j });
				visited[i][j] = 1;
				i = n;
				break;
			}
		}
	}
	if (q.size() == 0) {
		cout << 0 << "\n";
		exit(0);
	}
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			if (arr[nx][ny] > 0) {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				cnt++;
			}
		}
	}

	//cout << len << ", " << cnt << "\n";
	if (len == cnt) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				if (arr[i][j] == 0) {
					q.push({ i , j });
				}
			}
		}
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			visited[x][y] = 1;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
				if (visited[nx][ny] == 1) { continue; }
				if (arr[nx][ny] != 0) {
					arr[nx][ny] = arr[nx][ny] - 1 <= 0 ? 0 : arr[nx][ny] - 1;
				}
			}
		}
		len = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				if (arr[i][j] > 0) {
					len++;
				}
			}
		}
		ans++;
		bfs(len);
	}
	else {
		cout << ans << "\n";
		exit(0);
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) {
				cnt++;
			}
		}
	}
	bfs(cnt);
	return 0;
}
