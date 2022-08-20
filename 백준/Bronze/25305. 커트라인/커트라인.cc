#include<stdio.h>
#include<algorithm>
using namespace std;

int arr[1001] = { -1, };

int main() {
	
	int N = 0;
	int k = 0;
	scanf("%d %d", &N, &k);
	for (int i = 0; i < N; i++) {
		int x = 0;
		scanf("%d", &x);
		arr[i] = x;
	}

	sort(arr, arr+N, greater<int>());
	printf("%d", arr[k-1]);
}