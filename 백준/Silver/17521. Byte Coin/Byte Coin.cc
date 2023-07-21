#include <iostream>

using namespace std;

long long arr[16];
int type[16];	// 1: 매수 -1: 매도 0: 보유
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// 날짜 수, 초기 현금
	int n;
	long long w;	
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (arr[i] < arr[i + 1]) {
				type[i] = 1;
			}
		}
		else if (i == n - 1) {
			if (arr[i - 1] < arr[i]) {
				type[i - 1] = 1;
			}
			type[i] = -1;
		}
		else {
			if (arr[i] > arr[i - 1] && arr[i] >= arr[i + 1]) {
				type[i] = -1;
			}
			if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
				type[i] = 1;
			}
			if (arr[i - 1] < arr[i]) {
				type[i - 1] = 1;
			}
		}
	}

	long long coin = 0;

	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			coin = coin + (w / arr[i]);
			w = w - (w / arr[i]) * arr[i];
		}
		else if (type[i] == -1) {
			w = w + (coin * arr[i]);
			coin = 0;
		}
	}

	cout << w + (coin * arr[n - 1]);
	return 0;
}