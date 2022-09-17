//2021-12-11
#include<iostream>

using namespace std;

int arr[1001][1001] = { 1 };

int main() {
	int x; int y;
	cin >> x >> y;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			arr[i][j] = 1;
		}
	}
	for (int i = 1; i <= 1000; i++) {
		arr[i][i] = 1;
		arr[1][i] = i;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = i+1; j <= 1000; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j - 1]) % 10007;
		}
	}

	cout << arr[y][x] << endl;
	return 0;
}