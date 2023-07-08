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

	sort(arr, arr+n, greater<>());

	int idx = 0;
	int sum = 0;
	int len = n;
	while (true) {
		if (len - 3 >= 0) {
			sum += (arr[idx] + arr[idx + 1]);
			idx += 3;
			len -= 3;
		}
		else {
			break;
		}
	}
	int last = len % 3;
	for (int i = idx; i < idx + last; i++) {
		sum += arr[i];
	}
	cout << sum << "\n";

	return 0;
}