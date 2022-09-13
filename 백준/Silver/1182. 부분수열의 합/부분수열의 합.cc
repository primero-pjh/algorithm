#include <stdio.h>

bool visited[20];
int arr[20] = { 0, };
int list[20] = { 0, };
int n, s;
int result = 0;

void dfs(int idx, int cnt, int idx2) {
	//printf("idx: %d, cnt: %d\n", idx, cnt);
	if (cnt == idx) {
		int sum = 0;

		for (int i = 0; i < n; i++) {
			sum += arr[i];
		}
		if (sum == s) {
			
			result++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i >= idx2) {
			if (!visited[i]) {
				visited[i] = true;
				arr[i] = list[i];
				dfs(idx, cnt + 1, i + 1);
				arr[i] = 0;
				visited[i] = false;
			}
		}
		
	}
}

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	for (int i = 1; i <= n; i++) {
		//printf("dfs : %d\n", i);
		dfs(i, 0, 0);
	}

	printf("%d", result);
	return 0;
}