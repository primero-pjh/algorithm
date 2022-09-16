#include <queue>
#include <stdio.h>

using namespace std;

queue<int> q;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	int res[1000] = { 0, };
	int i = 1;
	printf("<");
	while (!q.empty()) {
		if (q.size() < 3) {
			if (i > k) {
				i = 1;
			}
		}
		if (i < k) {
			i++;
			int a = q.front();
			q.pop();
			q.push(a);
		}
		else if (i == k) {
			i = 1;
			if (q.size() == 1) {
				printf("%d", q.front());
			}
			else {
				printf("%d, ", q.front());
			}
			q.pop();
			n--;
		}
	}
	printf(">");
	return 0;
}