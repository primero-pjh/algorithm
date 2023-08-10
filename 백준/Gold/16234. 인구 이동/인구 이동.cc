#include <iostream>
#include <queue>

using namespace std;

int n, l, r;
int arr[50][50];
bool visited[50][50];
bool changed[50][50];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void reset_visited() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
			changed[i][j] = 0;
		}
	}
	return;
}
bool bfs(int x, int y) {
	bool is_reload = false;
	int sum = arr[x][y];
	int cnt = 1;
	q.push({ x , y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			if (visited[nx][ny] == 0) {
				if (abs(arr[nx][ny] - arr[x][y]) >= l && abs(arr[nx][ny] - arr[x][y]) <= r) {
					is_reload = true;
					changed[nx][ny] = 1;
					changed[x][y] = 1;
					visited[nx][ny] = 1;
					sum += arr[nx][ny];
					cnt++;
					q.push({ nx, ny });
				}
			}
		}
	}
	if (is_reload) {
		//cout << "sum, cnt: " << sum << " " << cnt << "\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (changed[i][j] == 1) {
					arr[i][j] = sum / cnt;
					changed[i][j] = 0;
				}
				//cout << arr[i][j] << " ";
			}
			//cout << "\n";
		}
	}
	return is_reload;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;
	while (1) {
		reset_visited();
		bool is_reload = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j] == 0) {
					if (bfs(i, j)) {
						is_reload = 1;
					}
				}
			}
		}
		
		if (is_reload) {
			ans++;
		}
		else {
			break;
		}
	}
	cout << ans << "\n";
	
	return 0;
}