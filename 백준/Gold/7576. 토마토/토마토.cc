#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>

using namespace std;

int arr[1001][1001];

// 상 하 좌 우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int p_num[1001][1001] = { 0, };
map<pair<int, int>, bool> visited;
queue<pair<int, int>> q;

int n, m;
int min_value = INT_MAX;
void bfs() {
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		int px = parent.first;
		int py = parent.second;
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			pair<int, int> child = pair<int, int>(nx, ny);
			if (nx < 0 || ny < 0) { continue; }
			if (nx >= m || ny >= n) { continue; }
			if (arr[nx][ny] == -1 || arr[nx][ny] == 1) { continue; }

			if (p_num[nx][ny] == 0) {
				q.push(child);
				visited[child] = 1;
				p_num[nx][ny] = p_num[px][py] + 1;
			}
			else {
				if (p_num[px][py] + 1 < p_num[nx][ny]) {
					q.push(child);
				}
				p_num[nx][ny] = min(p_num[px][py] + 1, p_num[nx][ny]);
			}
		}
	}

	/*for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << p_num[i][j] << " ";
		}
		cout << "\n";
	}*/

	return;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	vector<pair<int, int>> v;

	int cnt_0 = 0;
	int cnt_1 = 0;
	int cnt_n_1 = 0;

	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(pair<int, int>(i, j));
				visited[pair<int, int>(i, j)] = 1;
				cnt_1++;
			}
			else if (arr[i][j] == 0) {
				cnt_0++;
			}
			else {
				cnt_n_1++;
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
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			max_value = max(max_value, p_num[i][j]);
			if (p_num[i][j] > 0) {
				cnt++;
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