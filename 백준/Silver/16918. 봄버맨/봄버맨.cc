#include <iostream>
#include <queue>

using namespace std;

int r, c, n;
// 상 하 좌 우
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

char arr[201][201];
void bfs() {
	queue<pair<int, int>> q;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'O') {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		pair<int, int> parent = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = parent.first + dx[i];
			int ny = parent.second + dy[i];
			if (nx < 0 || ny < 0) { continue; }
			if (nx >= r || ny >= c) { continue; }
			if (arr[nx][ny] == '.') {
				arr[nx][ny] = 'O';
			}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = arr[i][j] == 'O' ? '.' : 'O';
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> n;
	int time = 1;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	if (n == 1) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
	} else if (n % 2 == 0) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << 'O';
			}
			cout << "\n";
		}
	}
	else {
		int len = (n / 2);
		for (int i = 0; i < len; i++) {
			bfs();
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}


	return 0;
}