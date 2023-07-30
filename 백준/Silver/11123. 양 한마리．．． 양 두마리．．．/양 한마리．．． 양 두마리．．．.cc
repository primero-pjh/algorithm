#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char arr[101][101];
bool visited[101][101];
void reset_visit() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = 0;
		}
	}
}
void bfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
		if (arr[nx][ny] == '.') { continue; }
		if (visited[nx][ny] == 0 && arr[nx][ny] == '#') {
			//cout << nx << ", " << ny << "\n";
			visited[nx][ny] = 1;
			bfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		reset_visit();
		int ans = 0;
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < str.size(); j++) {
				arr[i][j] = str[j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//cout << arr[i][j] << " ";
				if (visited[i][j] == 0 && arr[i][j] == '#') {
					//cout << i << ", " << j << "\n";
					visited[i][j] = 1;
					bfs(i, j);
					ans++;
				}
			}
			//cout << "\n";
		}

		cout << ans << "\n";

	}

	return 0;
}