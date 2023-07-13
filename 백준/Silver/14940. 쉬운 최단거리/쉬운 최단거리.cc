#include <iostream>
#include <queue>
#include <map>

using namespace std;

int arr[1001][1001];
int res[1001][1001];
// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int n, m;
map<pair<int, int>, bool> visited;
map<pair<int, int>, int> root;
queue<pair<int, int>> q;
void bfs(pair<int, int> top) {
	q.push(top);
	visited[top] = 1;
	root[top] = 0;
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			pair<int, int> child;
			int x = parent.first + dx[i];
			int y = parent.second + dy[i];
			child.first = x;
			child.second = y;

			if (x < 0 || y < 0) {
				continue;
			}
			if (x >= n || y >= m) {
				continue;
			}
			if (visited[child] == 1 || arr[x][y] == 0) { continue; }

			if (visited[child] == 0) {
				q.push(child);
				visited[child] = 1;
				root[child] = root[parent] + 1;
				res[x][y] = root[child];
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	pair<int, int> top;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				top.first = i;
				top.second = j;
			}
		}
	}
	bfs(top);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && res[i][j] == 0) {
				cout << -1 << " ";
			}
			else {
				cout << res[i][j] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}