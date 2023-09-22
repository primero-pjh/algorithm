#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[1001][1001];
int res[1001][1001];
bool visited1[1001][1001];
bool visited2[1001][1001];
int n, m, hx, hy, ex, ey;
struct type {
	int x, y, z;
};
queue<type> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 1000000000;

void bfs(int _hx, int _hy) {
	q.push({ _hx, _hy, 1 });
	visited1[_hx][_hy] = 1;
	res[_hx][_hy] = 0;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) { continue; }
			if (z == 1) {
				if (arr[nx][ny] == 0) {
					if (visited1[nx][ny] == 1) { continue; }
					visited1[nx][ny] = 1;
					res[nx][ny] = res[x][y] + 1;
					q.push({ nx, ny, 1 });
				}
				else {
					if (visited2[nx][ny] == 1) { continue; }
					visited2[nx][ny] = 1;
					res[nx][ny] = res[x][y] + 1;
					q.push({ nx, ny, 0 });
				}
			}
			else {
				if (arr[nx][ny] == 0) {
					if (visited2[nx][ny] == 1) { continue; }
					visited2[nx][ny] = 1;
					res[nx][ny] = res[x][y] + 1;
					q.push({ nx, ny, 0 });
				}
			}

			if (nx == ex && ny == ey) {
				ans = min(ans, res[nx][ny]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> hx >> hy >> ex >> ey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			res[i][j] = -1;
		}
	}
	bfs(hx, hy);
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}*/

	if (ans == 1000000000) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
	return 0;
}