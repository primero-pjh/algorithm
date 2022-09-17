#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n; int k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	int sum = 0;
	for (int i = arr.size() - 1; i >= 0; i--) {
		if (k >= arr[i]) {
			sum += (k / arr[i]);
			k %= arr[i];
		}
		if (k <= 0) {
			break;
		}
	}
	printf("%d ", sum);

	return 0;
}