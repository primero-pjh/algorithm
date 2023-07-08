#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001] = { 0, };


int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, greater<>());

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - i <= 0) {
			continue;
		}
		sum += (arr[i] - i);
	}
	cout << sum << "\n";
	return 0;
}