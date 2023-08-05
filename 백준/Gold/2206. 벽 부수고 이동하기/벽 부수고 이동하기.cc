#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[1001][1001];
bool visited1[1001][1001];
bool visited2[1001][1001];
int res[1001][1001];
int max_value = 0;
struct type {
	int x, y, z;
};

queue<type> q;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m;
void bfs(int a, int b, int c) {
	q.push({ a, b, c });
	visited1[a][b] = 1;
	visited2[a][b] = 1;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		//cout << x << ", " << y << ", " << z << "\n";
		q.pop();
		//visited[x][y] = 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z;
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) { continue; }
			if (arr[nx][ny] == 1) { 
				if (z == 1) {
					nz = 0;
				}
				else {
					continue;
				}
			}
			if (nz == 1) {
				if (visited1[nx][ny] == 0) {
					visited1[nx][ny] = 1;
					q.push({ nx, ny, nz });
					if (nx == n && ny == m) {
						if (res[nx][ny] != 0) {
							res[nx][ny] = min(res[nx][ny], res[x][y] + 1);
						}
						else {
							res[nx][ny] = res[x][y] + 1;
						}
					}
					else {
						res[nx][ny] = res[x][y] + 1;
					}
				}
			}
			else {
				if (visited2[nx][ny] == 0) {
					visited2[nx][ny] = 1;
					q.push({ nx, ny, nz });
					if (nx == n && ny == m) {
						if (res[nx][ny] != 0) {
							res[nx][ny] = min(res[nx][ny], res[x][y] + 1);
						}
						else {
							res[nx][ny] = res[x][y] + 1;
						}
					}
					else {
						res[nx][ny] = res[x][y] + 1;
					}
				}
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j + 1] = str[j] - '0';
		}
	}

	int ans = 0;
	res[1][1] = 1;
	bfs(1, 1, 1);
	
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}*/
	if (res[n][m] == 0) {
		cout << -1;
	}
	else {
		cout << res[n][m];
	}
	return 0;
}