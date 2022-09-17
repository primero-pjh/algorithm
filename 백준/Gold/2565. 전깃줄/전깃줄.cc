#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n;
int arr[101] = { 0, };
vector<int> dp;

void b_search(int start, int end, int num) {
	int mid = (start + end) / 2;
	while (start < end) {
		//printf("start: %d, end: %d\n", start, end);
		mid = (start + end) / 2;
		if (dp[mid] < num) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	mid = (start + end) / 2;
	dp[mid] = num;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		int a, b;
		scanf("%d %d", &a, &b);
		p.first = a; p.second = b;
		v.push_back(p);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		arr[i] = v[i].second;
	}

	dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		/*printf("i: %d ------------- \n", i);
		printf("dp: \n");
		for (int i = 0; i < dp.size(); i++) {
			printf("%d ", dp[i]);
		}
		printf("\n");*/
		if (dp[dp.size() - 1] < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			b_search(0, dp.size() - 1, arr[i]);
		}
	}
	/*for (int i = 0; i < dp.size(); i++) {
		printf("%d ", dp[i]);
	}*/
	printf("%d", n - dp.size());
	
	return 0;
}
