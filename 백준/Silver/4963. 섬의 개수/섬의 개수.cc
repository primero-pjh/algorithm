#include <iostream>
#include <map>
#include <queue>

using namespace std;

int arr[51][51];
// 상 하 좌 우 ↗ ↙ ↘ ↖
int dx[8] = { -1, 1, 0, 0, -1, 1, 1, -1 };
int dy[8] = { 0, 0, -1, 1, 1, -1, 1, -1 };
int w, h;

int cnt = 0;
map<pair<int, int>, bool> visited;
void bfs(pair<int, int> top) {
	queue<pair<int, int>> q;
	q.push(top);
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			pair<int, int> child;
			child.first = parent.first + dx[i];
			child.second = parent.second + dy[i];
			int x = child.first;
			int y = child.second;
			if (x < 0 || y < 0) {
				continue;
			}
			if (x >= h || y >= w) {
				continue;
			}
			if (arr[x][y] == 0) {
				continue;
			}
			if (visited[child] == 0) {
				q.push(child);
				visited[child] = 1;
			}
		}
	}
	cnt++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (cin >> w >> h) {
		cnt = 0;
		visited.clear();
		if (w == 0 && h == 0) {
			exit(0);
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
			}
		}

		
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr[i][j] == 0) {
					continue;
				}
				pair<int, int> top;
				top.first = i;
				top.second = j;
				if (visited[top] == 0) {
					visited[top] = 1;
					bfs(top);
				}
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}