// 2021-11-214
#include<iostream>
#include<vector>
#include<map>
using namespace std;

unsigned long long arr[1000001] = { 0 };

unsigned long long dfs(int x) {
	if (arr[x] != 0) {
		return arr[x];
	}
	else {
		return arr[x] = (dfs(x-2) + dfs(x-1)) % 15746;
	}
}

int main() {
	int n;
	cin >> n;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;

	for (int i = 3; i <= 1000000; i++) {
		arr[i] = (dfs(i - 2) + dfs(i - 1)) % 15746;
	}

	printf("%d", arr[n]);

	return 0;
}