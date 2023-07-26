#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int max_value = 1;
int arr[101][101];
bool temp[101][101] = { 0, };
bool visited[101][101] = { 0, };
int cnt = 0, n = 0;
void reset_visited() {
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			visited[i][j] = 0;
		}
	}
}
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
		if (temp[nx][ny] == 1) { continue; }
		if (visited[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= 101; i++) {
		reset_visited();
		int height = i;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][k] <= height) {
					temp[j][k] = 1;
				}
				else {
					temp[j][k] = 0;
				}
			}
		}
		cnt = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (visited[j][k] == 0 && temp[j][k] == 0) {
					visited[j][k] = 1;
					dfs(j, k);
					cnt++;
				}
			}
		}
		max_value = max(cnt, max_value);
	}
	cout << max_value << "\n";
}