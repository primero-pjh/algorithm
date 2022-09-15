#include <queue>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

queue<int> q;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	while (q.size() != 1) {
		q.pop();
		int a = q.front();
		q.pop();
		q.push(a);
	}
	printf("%d", q.front());
	return 0;
}