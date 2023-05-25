#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main() {
	int n;
	int arr[100][4];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arr[i][0] = x;
		arr[i][1] = y;
		arr[i][2] = x+10;
		arr[i][3] = y+10;
	}

	int count = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < n; k++) {
				if (i >= arr[k][0] && i < arr[k][2] && j >= arr[k][1] && j < arr[k][3]) {
					count++;
					break;
				}
			}
		}
	}
	printf("%d\n", count);

	return 0;
}