#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int arr[100001];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		int res = arr[i] * (n-i);
		max = max < res ? res : max;
	}

	cout << max << "\n";


	return 0;
}