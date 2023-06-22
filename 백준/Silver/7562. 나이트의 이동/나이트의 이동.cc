// 23.06.22
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;
int n, m, l;
queue<pair<int, int>> q;
int dx[9] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy[9] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int visited[301][301] = {0,};
void bfs(int x, int y) {
	pair<int, int> temp1;
	temp1.first = x;
	temp1.second = y;
	q.push(temp1);
	visited[x][y] = 1;
	while (!q.empty()) {
		pair<int, int> temp = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = temp.first + dx[i];
			int ny = temp.second + dy[i];
			if (nx < 0 || nx >= l || ny < 0 || ny >= l) {
				continue;
			} 
			if (visited[nx][ny] != 0) {
				continue;
			}
			else {
				pair<int, int> temp2;
				temp2.first = nx;
				temp2.second = ny;
				q.push(temp2);
				visited[nx][ny] = visited[temp.first][temp.second] + 1;
			}
		}
	}
}
void reset() {
	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			visited[i][j] = 0;
		}
	}
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l;
		int a, b, c, d;
		cin >> a >> b;
		cin >> c >> d;
		if ( a == c && b == d) {
			cout << 0 << "\n";
			continue;
		}
		else {
			bfs(a, b);
		}
		cout  << visited[c][d] -1 << "\n";
		reset();
	}
	return 0;
}