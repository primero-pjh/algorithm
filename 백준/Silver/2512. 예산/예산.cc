#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int arr[10001];

int bound() {
	int start = 0;
	int end = arr[n - 1];
	int mid = (start + end) / 2;
	int res = 0;
	while (start != end) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (mid >= arr[i]) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum > m) {
			end = mid;
		}
		else if (sum <= m) {
			start = mid +1 ;
			res = max(res, mid);
		}
		mid = (start + end) / 2;
	}
	return res;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	scanf("%d", &m);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	if (sum <= m) {
		printf("%d\n", arr[n - 1]);
	}
	else {
		printf("%d\n", bound());
	}
	return 0;
}