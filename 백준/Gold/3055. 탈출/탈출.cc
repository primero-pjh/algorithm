#include <iostream>
#include <vector>
#include <queue>

using namespace std;
char arr[51][51];
int res[51][51];
bool visited[51][51];
queue<pair<int, int>> q;

int water[51][51];
bool w_visited[51][51];
queue<pair<int, int>> wq;
int r, c;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

void w_bfs() {
	while (!wq.empty()) {
		int x = wq.front().first;
		int y = wq.front().second;
		wq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) { continue; }
			if (w_visited[nx][ny] == 1) { continue; }
			if (arr[nx][ny] == '.') {
				w_visited[nx][ny] = 1;
				wq.push({ nx, ny });
				water[nx][ny] = water[x][y] + 1;
			}
		}
	}
}
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= r || ny >= c) { continue; }
			if (visited[nx][ny] == 1) { continue; }
			if (arr[nx][ny] == '*' || arr[nx][ny] == 'X') { continue; }
			if (arr[nx][ny] == '.' && (water[nx][ny] == 0 || water[nx][ny] > res[x][y] + 1)) {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				res[nx][ny] = res[x][y] + 1;
			}
			if (arr[nx][ny] == 'D') {
				visited[nx][ny] = 1;
				q.push({ nx, ny });
				res[nx][ny] = res[x][y] + 1;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> r >> c;
	int a = 0, b = 0;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
			if (str[j] == 'S') {
				visited[i][j] = 1;
				q.push({ i, j });
			} else if (arr[i][j] == 'D') {
				a = i; b = j;
			}
			else if (arr[i][j] == '*') {
				visited[i][j] = 1;
				wq.push({ i, j });
			}
		}
	}
	w_bfs();
	bfs();
	/*cout << "-water-\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << water[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-res-\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "---\n";*/
	if (res[a][b] == 0) {
		cout << "KAKTUS";
	}
	else {
		cout << res[a][b];
	}
	return 0;
}