#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int arr[101][101][101];

struct tomatos {
	int x, y, z;
};


// 상 하 좌 우 위 아래
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };
int p_num[101][101][101] = {0,};
queue<tomatos> q;

int n, m, h;
int min_value = INT_MAX;
void bfs() {
	while (!q.empty()) {
		tomatos parent = q.front();
		q.pop();
		int px = parent.x;
		int py = parent.y;
		int pz = parent.z;
		for (int i = 0; i < 6; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			int nz = pz + dz[i];
			tomatos child = tomatos({ nx, ny, nz });
			if (nx < 0 || ny < 0 || nz < 0) { continue; }
			if (nx >= n || ny >= m || nz >= h) { continue; }
			if (arr[nz][nx][ny] == -1 || arr[nz][nx][ny] == 1) { continue; }

			if (p_num[nz][nx][ny] == 0) {
				q.push(child);
				p_num[nz][nx][ny] = p_num[pz][px][py] + 1;
			}
			else {
				if (p_num[pz][px][py] + 1 < p_num[nz][nx][ny]) {
					q.push(child);
				}
				p_num[nz][nx][ny] = min(p_num[pz][px][py] + 1, p_num[nz][nx][ny]);
			}
		}
	}

	/*for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cout << p_num[i][j][k] << " ";
			}
			cout << "\n";
		}
	}*/
	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> m >> n >> h;

	int cnt_0 = 0;
	int cnt_1 = 0;
	int cnt_n_1 = 0;


	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					q.push({ j, k, i  });
					cnt_1++;
				}
				else if (arr[i][j][k] == 0) {
					cnt_0++;
				}
				else {
					cnt_n_1++;
				}
			}
		}
	}

	// 안익은 토마토가 없는 경우
	if (cnt_0 == 0) {
		cout << "0" << "\n";
		exit(0);
	}

	bfs();

	int max_value = 0;
	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				max_value = max(max_value, p_num[i][j][k]);
				if (p_num[i][j][k] > 0) {
					cnt++;
				}
			}
		}
	}
	// 도달할 수 없는 토마토가 있는 경우
	if (cnt < (cnt_0)) {
		cout << -1 << "\n";
	}
	else {
		// 일반적인 경우
		cout << max_value << "\n";
	}
	return 0;
}