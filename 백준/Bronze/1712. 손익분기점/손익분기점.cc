//2021-11-06
#include<iostream>
#include<stdio.h>	
#include <string.h>
#include<map>
using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if (b >= c) {
		cout << -1 << endl;
		return 0;
	}

	long long result = 0;
	result = a / (c - b);
	cout << result + 1;

	return 0;
}