#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[1001];
	vector<int> res;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
		res.push_back(1);
	}

	// 증가하는 수열
	for (int i = 1; i < n; i++) {
		int m = 0;
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				m = max(m, res[j]);
				cnt++;
			}
		}
		if (cnt > 0) {
			res[i] = m + 1;

		}
	}
	// 감소하는 수열
	for (int i = 1; i < n; i++) {
		int m = 0;
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] < arr[j]) {
				m = max(m, res[j]);
				cnt++;
			}
		}
		if (cnt > 0 && (res[i] < m+1)) {
			res[i] = m + 1;
		}
	}

	int max = 0;
	for (int i = 0; i < res.size(); i++) {
		if (max < res[i]) {
			max = res[i];
		}
	}
	printf("%d ", max);

	return 0;
}