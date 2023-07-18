#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[64][64] = { 0, };
void dfs(int x, int y, int len) {
	//cout << "\n" << x << ", " << y << ", " << len << "\n";
	int total = len * len;
	int a = 0, b = 0;
	if (len <= 2) {
		for (int i = x; i < x + len; i++) {
			for (int j = y; j < y + len; j++) {
				if (arr[i][j] == 0) { a++; }
				else { b++; }
			}
		}

		if (a == total) { cout << 0; return; }
		else if (b == total) { cout << 1; return; }
		else { 
			cout << "(";
			for (int i = x; i < x + len; i++) {
				for (int j = y; j < y + len; j++) {
					cout << to_string(arr[i][j]);
				}
			}
			cout << ")";
		}
		return;
	}


	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (arr[i][j] == 0) {
				a++;
			}
			else {
				b++;
			}
		}
	}

	if (a == total) {
		cout << 0;
		return;
	}
	else if (b == total) {
		cout << 1;
		return;
	}
	else {
		int size = len / 2;
		cout << "(";
		dfs(x, y, size);
		dfs(x, y + size, size);
		dfs(x + size, y, size);
		dfs(x + size, y + size, size);
		cout << ")";
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	dfs(0, 0, n);
	return 0;
}