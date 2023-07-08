#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001] = { 0, };
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<>());

	double sum = arr[0];
	for (int i = n - 1; i >= 1; i--) {
		sum += (double)(arr[i] / 2.0);
	}

	cout << sum << "\n";

	return 0;
}