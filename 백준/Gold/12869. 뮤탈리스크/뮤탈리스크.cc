#include <iostream>
#include <queue>
using namespace std;

int n,a,b,c;
struct type {
	int x, y, z;
};
queue<type> q;
int dx[6] = { 9, 9, 3, 3, 1, 1 };
int dy[6] = { 3, 1, 1, 9, 3, 9 };
int dz[6] = { 1, 3, 9, 1, 9, 3 };
bool visited[61][61][61];
int res[61][61][61];
void bfs() {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x - dx[i];
			int ny = y - dy[i];
			int nz = z - dz[i];
			if (nx <= 0) { nx = 0; }
			if (ny <= 0) { ny = 0; }
			if (nz <= 0) { nz = 0; }
			if (visited[nx][ny][nz] == 0) {
				visited[nx][ny][nz] = 1;
				res[nx][ny][nz] = res[x][y][z] + 1;
				q.push({ nx, ny, nz });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	if (n == 3) {
		cin >> a >> b >> c;
	}
	else if (n == 2) {
		cin >> a >> b;
	}
	else if (n == 1) {
		cin >> a;
	}
	
	q.push({ a, b, c });
	visited[a][b][c] = 1;
	bfs();
	cout << res[0][0][0] << '\n';
	return 0;
}