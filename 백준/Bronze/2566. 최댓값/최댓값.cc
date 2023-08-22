#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int max_value = 0;
	int arr[10][10];
	int a = 0, b = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			if (max_value <= arr[i][j]) {
				max_value = arr[i][j];
				a = i;
				b = j;
			}
		}
	}
	cout << max_value << "\n" << (a+1) << " " << (b+1);
	return 0;
}