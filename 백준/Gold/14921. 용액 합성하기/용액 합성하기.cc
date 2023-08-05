#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int arr[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = n - 1;
	int min_value = 200000000;
	int res = 0;
	while (start < end) {
		int value = arr[start] + arr[end];
		if (min_value >= abs(value)){
			min_value = abs(value);
			res = value;
		}
		if (abs(arr[start]) > abs(arr[end])) {
			start++;
		}
		else {
			end--;
		}
	}

	cout << res;
	return 0;
}