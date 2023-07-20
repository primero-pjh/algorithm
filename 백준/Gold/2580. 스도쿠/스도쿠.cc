#include <iostream>

using namespace std;

int arr[10][10];

void dfs(int x, int y, int cnt) {
	//cout << x << ", " << y << ", " << cnt << "\n";
	
	int value = arr[x][y];
	for (int i = 1; i <= 9; i++) {
		if (i != x && value == arr[i][y] && arr[i][y] != 0) {
			return;
		}
		if (i != y && value == arr[x][i] && arr[x][i] != 0) {
			return;
		}
	}

	//cout << "x, y: " << x << ", " << y << "\n";
	int a = ((x - 1) / 3) * 3 + 1;
	int b = ((y - 1)/ 3) * 3 + 1;
	//cout << "a, b: " << a << ", " << b << "\n";
	for (int i = a; i < a + 3; i++) {
		for (int j = b; j < b + 3; j++) {
			if (arr[i][j] != 0 && i != x && j != y && value == arr[i][j]) {
				return;
			}
		}
	}

	if (cnt <= 0) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (arr[i][j] == 0) {
				for (int k = 1; k <= 9; k++) {
					arr[i][j] = k;
					dfs(i, j, cnt - 1);
					arr[i][j] = 0;
				}
				return;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int cnt = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				cnt++;
			}
		}
	}

	dfs(1, 1, cnt);

	
	return 0;
}