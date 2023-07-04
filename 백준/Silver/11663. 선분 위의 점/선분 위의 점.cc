#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001] = { 0, };

int binary_search_start(int search, int start, int end) {
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] < search) {
			start = mid + 1;
		}
		else if (arr[mid] == search) {
			return mid;
		}
		else if ( arr[mid] > search ) {
			end = mid - 1;
		}
	}
	return start;
}
int binary_search_end(int search, int start, int end) {
	int mid = 0;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] < search) {
			start = mid + 1;
		}
		else if (arr[mid] == search) {
			return mid;
		}
		else if (arr[mid] > search) {
			end = mid - 1;
		}
	}
	return end;
}

int main() {
	int n, m;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int start_idx = binary_search_start(a, 0, n-1);
		int end_idx = binary_search_end(b, 0, n-1);
		if (end_idx < start_idx) {
			cout << 0 << "\n";
		}
		else {
			cout << (end_idx - start_idx + 1) << "\n";
		}
	}
	return 0;
}