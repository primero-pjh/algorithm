#include <iostream>
#include <algorithm>

using namespace std;

int n, x;
int arr[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;
	int start = 0;
	int end = n - 1;
	int ans = 0;
	sort(arr, arr + n);
	while (start < end) {
		if (arr[start] + arr[end] > x) {
			end--;
		} else if (arr[start] + arr[end] == x) {
			ans++;
			start++;
			end--;
		}
		else {
			start++;
		}
	}

	cout << ans;
	return 0;
}