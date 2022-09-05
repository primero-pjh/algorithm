#include <stdio.h>

using namespace std;

int main() {
	int a, b, c, d;
	int x[100][100] = { 0, };
	int y[100][100] = { 0, };
	int res[100][100] = { 0, };
	scanf("%d %d", &a, &b);
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%d", &x[i][j]);
		}
	}

	scanf("%d %d", &c, &d);
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			scanf("%d", &y[i][j]);
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++) {
			int s = 0;
			for (int k = 0; k < c; k++) {
				s += x[i][k] * y[k][j];
			}
			res[i][j] = s;
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}

	return 0;
}