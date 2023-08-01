#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[51][51];
int res[51][51];
bool visited[51][51];
queue<pair<int, int>> q;

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void bfs() {
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		int x = parent.first;
		int y = parent.second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (visited[nx][ny] == 0 && arr[nx][ny] == 0) { 
				res[nx][ny] = res[x][y] + 1;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i, j });
				cnt++;
			}
			//visited[i][j] = 1;
		}
	}
	bfs();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cout << res[i][j] << " ";
			ans = max(res[i][j], ans);
		}
		//cout << "\n";
	}
	cout << ans;
	return 0;
}