#include <iostream>
#include <string>
#include <map>

using namespace std;

string arr[101][3];
map<string, int> res;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			for (int k = 1; k <= 9; k++) {
				if (i == j || j == k || i == k) {
					continue;
				}
				for (int q = 0; q < n; q++) {
					int strike = 0;
					int ball = 0;
					if (i == arr[q][0][0] - '0') {
						strike++;
					}
					else {
						if (i == arr[q][0][1] - '0' || i == arr[q][0][2] - '0') {
							ball++;
						}
					}
					if (j == arr[q][0][1] - '0') {
						strike++;
					}
					else {
						if (j == arr[q][0][0] - '0' || j == arr[q][0][2] - '0') {
							ball++;
						}
					}
					if (k == arr[q][0][2] - '0') {
						strike++;
					}
					else {
						if (k == arr[q][0][0] - '0' || k == arr[q][0][1] - '0') {
							ball++;
						}
					}

					if (strike == arr[q][1][0] - '0' && ball == arr[q][2][0] - '0') {
						string new_str = to_string(i) + to_string(j) + to_string(k);
						res[new_str]++;
					}
				}
			}
		}
	}

	int cnt = 0;
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		if (iter->second >= n) {
			cnt++;
			//cout << iter->first << "\n";
		}
	}
	cout << cnt << "\n";
	return 0;
}