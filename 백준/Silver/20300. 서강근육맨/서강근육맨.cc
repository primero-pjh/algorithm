#include <iostream>
#include <algorithm>

using namespace std;

unsigned long long arr[10001];
int main() {
	int n; 
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	unsigned long long min_value = 0;
	int start = 0;
	int end = 0;
	if (n % 2 == 0) {
		start = 0;
		end = n - 1;
		min_value = arr[start] + arr[end];
	}
	else {
		start = 0;
		end = n - 2;
		min_value = arr[n-1];
	}
	while (start <= end) {
		unsigned long long value = arr[start] + arr[end];
		min_value = max(min_value, value);
		start++;
		end--;
	}
	cout << min_value;
	return 0;
}