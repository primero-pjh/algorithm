#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, l;
	cin >> n >> l;
	int arr[1001];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (l >= arr[i]) {
			l++;
		}
	}
	cout << l;
	return 0;
}