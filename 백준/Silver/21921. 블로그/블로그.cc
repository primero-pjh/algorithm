#include <iostream>

using namespace std;

int arr[250001] = { 0, };
int res[250001] = { 0, };

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		sum += arr[i];
		if (i >= x) {
			res[i] = sum;
			max = max > sum ? max : sum;
			sum = sum - arr[i - x + 1];
		}
	}

	if (max == 0) {
		cout << "SAD" << "\n";
		exit(0);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (max == res[i]) {
			cnt++;
		}
	}
	cout << max << "\n";
	cout << cnt << "\n";

	return 0;
}

