#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, t;
int arr[101][101];
bool visited1[101][101];
bool visited2[101][101];
int res[101][101][2];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct type {
	int x, y, z;
};
queue<type> q;
void bfs(int a, int b) {
	q.push({ a, b, 0 });
	visited1[a][b] = 1;
	visited2[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) { continue; }
			if (z == 1) {
				if (visited2[nx][ny] == 0) {
					visited2[nx][ny] = 1;
					res[nx][ny][1] = res[x][y][1] + 1;
					q.push({ nx, ny, 1 });
				}
			}
			else {
				if (arr[nx][ny] == 1) { continue; }
				if (visited1[nx][ny] == 0) {
					visited1[nx][ny] = 1;
					res[nx][ny][0] = res[x][y][0] + 1;
					if (arr[nx][ny] == 2) {
						visited2[nx][ny] = 1;
						res[nx][ny][1] = res[x][y][0] + 1;
						q.push({ nx, ny, 1 });
					}
					else {
						q.push({ nx, ny, 0 });
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	bfs(1, 1);
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j][1] << " ";
		}
		cout << "\n";
	}*/

	int ans = 0;
	if (res[n][m][0] != 0) {
		ans = min(res[n][m][0], res[n][m][1]);
	}
	else {
		ans = res[n][m][1];
	}
	if (ans == 0) {
		cout << "Fail";
	}
	else {
		if (ans <= t) {
			cout << ans;
		}
		else {
			cout << "Fail";
		}
	}
	return 0;
}