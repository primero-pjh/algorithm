#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

int arr[100000] = { 0, };
int Div[100000] = { 0, };

int k = 0;
int result = 0;
int count = 0;
int main(void) {

	for (int i = 0; i < 100000; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == -1) {
			break;
		}
		count++;
	}

	for (int i = 0; i < count + 1; i++) {
		if (arr[i] == -1) {
			break;
		}
		printf("%d", arr[i]);

		for (int j = 1; j < arr[i]; j++) {
			if (arr[i] % j == 0) {
				Div[k] = j;

				result += Div[k];
				k++;
			}
		}
		if (result == arr[i]) {
			for (int j = 0; j < k; j++) {
				if (j == 0) {
					printf(" = %d", Div[j]);
				}
				else  {
					printf(" + %d", Div[j]);
				}
			}
			result = 0;
			k = 0;
			printf("\n");

		}
		else {
			printf(" is NOT perfect.");
			printf("\n");
			result = 0;
			k = 0;


		}
	}
	return 0;
}