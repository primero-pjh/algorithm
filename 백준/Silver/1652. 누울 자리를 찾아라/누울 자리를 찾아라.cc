#include <iostream>

using namespace std;
int n;
int arr[101][101];
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

	int res1 = 0, res2 = 0;
	for (int i = 0; i < n; i++) {
		char prev = ' ';
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) {
					res1++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2) {
			res1++;
		}
	}

	for (int i = 0; i < n; i++) {
		char prev = ' ';
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j][i] == '.') {
				cnt++;
			}
			else {
				if (cnt >= 2) {
					res2++;
				}
				cnt = 0;
			}
		}
		if (cnt >= 2) {
			res2++;
		}
	}

	cout << res1 << " " << res2;
}