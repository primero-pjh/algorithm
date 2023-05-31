// 2023.05.31
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int j = 0; j < b; j++) {
			int c, d;
			scanf("%d %d", &c, &d);
		}
		printf("%d\n", a - 1);
	}
	return 0;
}