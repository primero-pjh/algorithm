 //2021-11-06
#include<iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

int main() {
	char a[101];
	std::cin >> a;
	int count = strlen(a);
	for (int i = 0; i < strlen(a); i++) {
		if ((a[i] == 'l' || a[i] == 'n') && a[i + 1] == 'j') count--;
		if (a[i] == 'd' && a[i + 1] == 'z' && a[i + 2] == '=') count--;
		if (a[i] == '=' || a[i] == '-') count--;
	}
	printf("%d", count);

	return 0;
}