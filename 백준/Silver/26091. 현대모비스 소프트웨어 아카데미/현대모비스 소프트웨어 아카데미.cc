#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int start = 0;
	int end = n - 1;
	int sum = 0;
	int ans = 0;
	sum += (arr[start] + arr[end]);
	while (start < end) {
		if (sum >= m) {
			start++;
			end--;
			ans++;
			sum = (arr[start] + arr[end]);
		}
		else {
			start++;
			sum += arr[start];
		}
	}
	cout << ans;
	return 0;
}