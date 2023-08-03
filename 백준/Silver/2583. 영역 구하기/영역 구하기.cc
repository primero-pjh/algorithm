#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int m, n, k;
int arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int bfs(pair<int, int> top) {
	q.push(top);
	int cnt = 1;
	visited[top.first][top.second] = 1;
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		int x = parent.first;
		int y = parent.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (arr[nx][ny] == 1) { continue; }
			if (visited[nx][ny] == 0) {
				cnt++;
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				arr[nx][ny] = 1;
			}
		}
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x = x2 - x1;
		int y = y2 - y1;
		for (int j = y1; j < y1 + y; j++) {
			for (int k = x1; k < x1 + x; k++) {
				arr[j][k] = 1;
			}
		}
	}

	int ans = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				q.push({ i, j });
				int a = bfs(pair<int, int>(i, j));
				v.push_back(a);
				ans++;
			}
		}
	}
	cout << ans << "\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}