
#include <iostream>
#include<queue>

using namespace std;

priority_queue<int> q;

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			if (q.empty() == false) {
				printf("%d\n", q.top());
				q.pop();
			}
			else {
				printf("%d\n", 0);
			}
			continue;
		}
		q.push(a);
	}
	
	return 0;
}