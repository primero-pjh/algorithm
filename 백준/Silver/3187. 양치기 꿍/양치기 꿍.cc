#include <iostream>
#include <queue>

using namespace std;

int n, m;
char arr[251][251];
bool visited[251][251];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

void bfs(int a, int b) {
	vector<pair<int, int>> v;
	q.push({ a, b });
	visited[a][b] = 1;
	int v_cnt = 0;
	int k_cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		v.push_back({ x, y });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			if (arr[nx][ny] == '#') { continue; }
			if (visited[nx][ny] == 0) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				if (arr[nx][ny] == 'v') {
					v_cnt++;
				}
				if (arr[nx][ny] == 'k') {
					k_cnt++;
				}
			}
		}
	}

	if (v_cnt >= k_cnt) {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			if (arr[x][y] == 'k') {
				arr[x][y] = '.';
			}
		}
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			int x = v[i].first;
			int y = v[i].second;
			if (arr[x][y] == 'v') {
				arr[x][y] = '.';
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j + 1] = str[j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 'k' && visited[i][j] == 0) {
				bfs(i, j);
			}
		}
	}

	int v_cnt = 0;
	int k_cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 'v') {
				v_cnt++;
			}
			else if (arr[i][j] == 'k') {
				k_cnt++;
			}
		}
	}
	cout << k_cnt << " " << v_cnt << "\n";
	return 0;
}