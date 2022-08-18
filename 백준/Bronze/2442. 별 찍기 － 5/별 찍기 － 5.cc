#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int cnt = 0;

int main() {
	scanf("%d", &cnt);
	int max = 2 * cnt - 1;
	for (int i = 0; i < cnt; i++) {
		int a = cnt - (i+1);
		for (int j = 0; j < max; j++) {
			if (j < a) {
				printf("%s", " ");
				continue;
			}
			if (j >=  max - a) {
				//printf("%s", "-");
				continue;
			}
			printf("%s", "*");
			
		}
		printf("\n");
	}
}
