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
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < i + 1; j++) {
			printf("%s", "*");
		}
		printf("\n");
	}
}