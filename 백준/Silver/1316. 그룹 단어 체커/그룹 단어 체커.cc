 //2021-11-06
#include<iostream>
#include<stdio.h>	
#include <string.h>
#include<map>
using namespace std;

int main() {
	int n = 0;
	int count = 0;
	cin >> n;
	while (n--) {
		char a[101];
		cin >> a;
		char first = a[0];
		map<char, bool> m; m.clear();
		m[first] = true;
		for (int i = 1; i < strlen(a); i++) {
			if (first == a[i]) {
				continue;
			}
			else {
				if (m[a[i]] == true) {
					count--;
					break;
				}
				first = a[i];
				m[first] = true;
			}

		}
		count++;
	}
	
	cout << count << endl;

	return 0;
}