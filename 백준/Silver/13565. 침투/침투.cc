#include <iostream>
#include <string>
#include <queue>

using namespace std;

int arr[1001][1001];
bool visited[1001][1001];
int n, m;
queue<pair<int, int>> q;
// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
void bfs() {
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = parent.first + dx[i];
			int ny = parent.second + dy[i];
			if (nx <= 0 || ny <= 0) { continue; }
			if (nx > n || ny > m) { continue; }
			if (arr[nx][ny] == 1) { continue; }
			if (!visited[nx][ny] && arr[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);  cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j + 1] = str[j] - '0';
			if (i == 1) {
				if (str[j] == '0') {
					q.push({ i, j + 1 });
					visited[i][j + 1] = 1;
				}
			}
		}
	}

	bfs();
	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}*/
	for (int i = 1; i <= m; i++) {
		if (visited[n][i] == 1) {
			cout << "YES";
			exit(0);
		}
	}
	cout << "NO";
	exit(0);
	return 0;
}