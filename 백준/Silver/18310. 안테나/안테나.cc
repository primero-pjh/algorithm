#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001];
int visited[200001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		visited[arr[i]] = 1;
	}
	sort(arr, arr + n);
	int mid = 0;
	if (n % 2 == 0) {
		mid = (n - 1) / 2;
	}
	else {
		mid = n / 2;
	}
	int value = arr[mid];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += abs(arr[i] - value);
	}
	mid++;
	while (1) {
		int value = arr[mid];
		int res_sum = 0;
		for (int i = 0; i < n; i++) {
			res_sum += abs(arr[i] - value);
		}
		if (res_sum >= sum) {
			mid--;
			break;
		}
		else {
			sum = res_sum;
		}
	}
	cout << arr[mid];
	return 0;
}