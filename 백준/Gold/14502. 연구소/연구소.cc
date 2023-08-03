#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
int arr[8][8];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int max_value = 0;
vector<pair<int, int>> v;

void bfs(int temp[8][8]) {
	bool visited[8][8] = { 0, };
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].first, v[i].second });
	}
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		int x = parent.first;
		int y = parent.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (temp[nx][ny] != 0) { continue; }
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				temp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) {
				ans++;
			}
		}
	}
	max_value = max(max_value, ans);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				v.push_back({ i, j });
				//q.push({ i, j });
			}
		}
	}

	int len = n * m;
	for (int i = 0; i < len; i++) {
		int x1 = i / m;
		int y1 = i % m;
		if (arr[x1][y1] != 0) { continue; }
		for (int j = i+1; j < len; j++) {
			int x2 = j / m;
			int y2 = j % m;
			if (arr[x2][y2] != 0) { continue; }
			for (int k = j+1; k < len; k++) {
				int x3 = k / m;
				int y3 = k % m;
				if (arr[x3][y3] != 0) { continue; }
				//cout << x1 << ", " << y1 << ", " << x2 << ", " << y2 << ", " << x3 << ", " << y3 << "\n";
				int temp[8][8];
				copy(&arr[0][0], &arr[0][0] + 8 * 8, &temp[0][0]);
				
				temp[x1][y1] = 1;
				temp[x2][y2] = 1;
				temp[x3][y3] = 1;
				bfs(temp);
			}
		}
	}

	cout << max_value;
	return 0;
}