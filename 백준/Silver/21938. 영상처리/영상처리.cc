#include <iostream>
#include <map>
#include <vector>

using namespace std;

double graph[1001][1001];
bool visited[1001][1001];
int n, m, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
		if (visited[nx][ny] == 0 && graph[nx][ny] == 255) {
			visited[nx][ny] = 1;
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	int r, g, b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> r >> g >> b;
			double sum = (r + g + b) / 3.0;
			graph[i][j] = sum;
		}
	}
	cin >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] >= t) {
				graph[i][j] = 255;
			}
			else {
				graph[i][j] = 0;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i][j] == 255 && visited[i][j] == 0) {
				visited[i][j] = 1;
				dfs(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}