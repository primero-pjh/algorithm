// 2021-10-29
#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1000] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		int count = 0;
		int x = (int)sqrt(arr[i]);
		if (arr[i] == 1) {
			continue;
		}
		for (int j = 2; j <= x; j++) {
			if (arr[i] % j == 0) {
				count++;
			}
		}
		if (count == 0) {
			result++;
		}
	}
	cout << result << endl;

	return 0;
}