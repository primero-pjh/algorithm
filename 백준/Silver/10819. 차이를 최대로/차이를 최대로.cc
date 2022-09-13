#include <stdio.h>
#include <algorithm>
 
using namespace std;

int n;
int arr[8];
int list[8];
bool visited[8];
int m_v = 0;
void dfs(int idx) {
	if (idx == n) {
		int sum = 0;
		for (int i = 2; i <= n; i++) {
			sum = sum + abs(arr[i-2] - arr[i-1]);
		}
		/*for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");*/
		m_v = max(m_v, sum);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[idx] = list[i];
			dfs(idx + 1);
			visited[i] = false;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	dfs(0);
	printf("%d", m_v);

	return 0;
}