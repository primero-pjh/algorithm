#include <iostream>

using namespace std;

int arr[501][501];
int dp[501];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int h, w;
	cin >> h >> w;

	for (int i = 1; i <= w; i++) {
		int a;
		cin >> a;
		for (int j = h; j > h-a; j--) {
			arr[j][i] = 1;
		}
	}
	for (int i = 1; i <= w; i++) {
		arr[h + 1][i] = 1;
	}

	int sum = 0;
	for (int i = 1; i <= h; i++) {
		bool is_start = false;
		int start = 0;
		int end = 0;
		int water = 0;
		for (int j = 1; j <= w; j++) {
			if (arr[i][j] == 1) {
				if (!is_start) {
					is_start = true;
				}
				else {
					sum += water;
					water = 0;
				}
			}
			else {
				if (is_start) {
					water++;
				}
			}
		}
		//cout << water << "\n";
	}

	cout << sum;
	/*cout << "---" << "\n";
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}*/

	
	return 0;
}