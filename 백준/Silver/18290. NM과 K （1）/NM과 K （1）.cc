#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[10][10];
int visited[10][10];
int max_value = -2100000000;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
vector<pair<int, int>> v;
int n, m, k;

void dfs(int x, int y) {
	if (v.size() == k) {
		int sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += arr[v[i].first][v[i].second];
		}
		max_value = max(sum, max_value);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] >= 1) { continue; }
			v.push_back({ i, j });
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
				visited[nx][ny]++;
			}
			visited[i][j]++;
			dfs(i, j);
			v.pop_back();
			visited[i][j]--;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
				visited[nx][ny]--;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j]++;
			v.push_back({ i, j });
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
				visited[nx][ny]++;
			}
			dfs(i, j);
			visited[i][j]--;
			v.pop_back();
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
				visited[nx][ny]--;
			}
		}
	}

	cout << max_value;
	return 0;
}