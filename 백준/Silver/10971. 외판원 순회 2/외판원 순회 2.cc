#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[10] = { 0, };
int list[10][10] = { 0, };
int n;
bool visited[10];
int res = 2100000000;

void dfs(int cnt) {
	if (cnt == n) {
		arr[n] = arr[0];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (list[arr[i]-1][arr[i + 1]-1] == 0) {
				//printf("i: %d, [%d, %d = %d] return\n", i, arr[i], arr[i+1], list[arr[i]][arr[i+1]]);
				return;
			}
			sum += list[arr[i]-1][arr[i + 1]-1];
		}
		res = min(res, sum);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &list[i][j]);
		}
	}

	dfs(0);
	printf("%d", res);

	return 0;
}