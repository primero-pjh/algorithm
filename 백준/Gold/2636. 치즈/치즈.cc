#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int t = 0;
int ans = 0;
void push_ch() {
	
}
void bfs(int top_x, int top_y) {
	int cnt = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			visited[i][j] = 0;
		}
	}
	q.push({ top_x , top_y });
	visited[top_x][top_y] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[nx][ny] == 1) { continue; }
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (arr[nx][ny] == 1) {
				v.push_back({ nx, ny });
				cnt++;
			}
			else {
				q.push({ nx, ny });
			}
			visited[nx][ny] = 1;
		}
	}
	if (v.size() == 0) {
		cout << t << "\n" << ans;
		exit(0);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		arr[v[i].first][v[i].second] = 0;
		v.pop_back();
	}
	t++;
	ans = cnt;
	bfs(0, 0);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				ans++;
			}
		}
	}
	bfs(0, 0);
	return 0;
}