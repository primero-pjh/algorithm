#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char arr[601][601];
bool visited[601][601];

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int ans = 0;

queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visited[nx][ny] == 1 || arr[nx][ny] == 'X') { continue; }
			if (arr[nx][ny] == 'O') {
				visited[nx][ny] = 1;
				q.push({ nx , ny });
			}
			if (arr[nx][ny] == 'P') {
				ans++;
				visited[nx][ny] = 1;
				q.push({ nx , ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
			if (str[j] == 'I') {
				q.push({ i, j });
			}
		}
	}

	bfs();
	if (ans == 0) {
		cout << "TT";
	}
	else {
		cout << ans;
	}
	return 0;
}