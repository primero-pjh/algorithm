#include <iostream>

using namespace std;

int n;
char arr[11][11];
char res[11][11];
int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
char search(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) { continue; }
		if (arr[nx][ny] == '*') { cnt++; }
	}
	return (cnt + '0');
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j];
		}
	}
	
	bool is_win = true;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == 'x') {
				if (arr[i][j] == '*') { is_win = false; }
				res[i][j] = search(i, j);
			}
			else {
				res[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '*') {
				if (!is_win) {
					cout << '*';
				}
				else {
					cout << res[i][j];
				}
			}
			else {
				cout << res[i][j];
			}
		}
		cout << "\n";
	}
}