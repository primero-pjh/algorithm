#include <iostream>
#include <queue>

using namespace std;

int n, m, l, r;
int arr[1001][1001];
bool visited[1001][1001][5];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
struct type {
	int x, y, le, ri, lr;
};
queue<type> q;
int ans = 0;

void bfs(int a, int b) {
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int le = q.front().le;
		int ri = q.front().ri;
		int lr = q.front().lr;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (i == 2 && le <= 0) { continue; }
			if (i == 3 && ri <= 0) { continue; }
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (arr[nx][ny] == 1) { continue; }
			if (visited[nx][ny][(a == x && b == y) ? i + 1 : lr] == 1) { continue; }
			visited[nx][ny][(a == x && b == y) ? i + 1 : lr] = 1;
			if (i == 2) {
				q.push({ nx, ny, le - 1, ri, (a == x && b == y) ? i + 1 : lr });
			}
			else if (i == 3) {
				q.push({ nx, ny, le, ri - 1, (a == x && b == y) ? i + 1 : lr });
			}
			else {
				q.push({ nx, ny, le, ri, (a == x && b == y) ? i + 1 : lr });
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> l >> r;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 2) {
				q.push({ i, j, l, r, 0 });
				a = i; b = j;
				visited[i][j][1] = 1;
				visited[i][j][2] = 1;
				visited[i][j][3] = 1;
				visited[i][j][4] = 1;
			}
		}
	}
	bfs(a, b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j][1] || visited[i][j][2] || visited[i][j][3] || visited[i][j][4]) {
				ans++;
			}
			//cout << (visited[i][j][1] || visited[i][j][2] || visited[i][j][3] || visited[i][j][4]) << " ";
		}
		//cout << "\n";
	}
	cout << ans << "\n";
	return 0;
}