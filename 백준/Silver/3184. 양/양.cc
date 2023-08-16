#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
queue<pair<int, int>> q;
char arr[250][250];
bool visited[250][250];

int dx[4] = { -1, 1, 0, 0 };
int n, m;
int dy[4] = { 0,0,-1,1 };
void bfs(int a, int b) {
	vector<pair<int, int>> v;
	v.push_back({ a,b });
	q.push({ a, b });
	visited[a][b] = 1;
	int o_cnt = 0;
	int v_cnt = 0;
	if (arr[a][b] == 'o') {
		o_cnt++;
	}
	if (arr[a][b] == 'v') {
		v_cnt++;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) { continue; }
			if (arr[nx][ny] == '#') { continue; }
			if (visited[nx][ny] == 0) {
				if (arr[nx][ny] == 'o') {
					o_cnt++;
				}
				if (arr[nx][ny] == 'v') {
					v_cnt++;
				}
				q.push({ nx, ny });
				visited[nx][ny] = 1;
				v.push_back({ nx, ny });
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		if (arr[x][y] == '.' || arr[x][y] == '#') { continue; }
		if (o_cnt > v_cnt) {
			if (arr[x][y] == 'v') { arr[x][y] = '.'; }
		}
		else {
			if (arr[x][y] == 'o') { arr[x][y] = '.'; }
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 0 && (arr[i][j] != '.' && arr[i][j] != '#')) {
				bfs(i, j);
			}
		}
	}

	int o_cnt = 0;
	int v_cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'o') {
				o_cnt++;
			}
			if (arr[i][j] == 'v') {
				v_cnt++;
			}
		}
	}
	cout << o_cnt << " " << v_cnt;
	return 0;
}