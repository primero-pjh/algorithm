// 2021-11-25
#include<iostream>
#include<algorithm>
using namespace std;

int arr[501][501];
int res[501][501];

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i+1; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	res[0][0] = arr[0][0];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0) {
				res[i][j] = arr[i][j] + res[i-1][0];
			}
			else if (j == i) {
				res[i][j] = arr[i][j] + res[i - 1][j - 1];
			}
			else if (j >= 1 && j <= i-1) {
				res[i][j] = max(res[i - 1][j - 1] + arr[i][j], res[i - 1][j] + arr[i][j]);
			}
		}
	}

	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < res[n][i]) {
			max = res[n][i];
		}
	}
	cout << max << endl;
	return 0;
}