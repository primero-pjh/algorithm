#include<stdio.h>
#include<algorithm>
#include<cmath>

using namespace std;
int n, k;
int arr[200000] = { 0, };
int cnt = 0;
long long result = 0;
void b_search(int start, int end) {
	cnt = k;
	//printf("start: %d, end: %d\n", start, end);
	if (start > end) {
		printf("%lld\n", result);
		exit(0);
	}
	long long mid = (start + end) / 2;
	//printf("mid: %lld\n", mid);
	int idx = 0;
	cnt--;
	for (int i = 1; i < n; i++) {
		long long diff = (long long)(arr[i]) - arr[idx];
		if (diff >= mid) {
			//printf("diff: %lld\n", diff);
			cnt--;
			idx = i;
		}
	}
	
	if (cnt <= 0) {
		result = mid;
		b_search(mid+1, end);
	}
	else {
		b_search(start, mid-1);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	cnt = k;
	int max_v = 0;
	int min_v = 1000000000;
	for (int i = 0; i < n; i++) {
		int a = 0;
		scanf("%d", &a);
		if (max_v < a) { max_v = a; }
		if (min_v > a) { min_v = a; }
		arr[i] = a;
	}

	sort(arr, arr + n);
	int end = (max_v - min_v);
	b_search(0, end);

	return 0;
}