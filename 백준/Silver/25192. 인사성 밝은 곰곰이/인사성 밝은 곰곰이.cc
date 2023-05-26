#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<string>
#include<iostream>
#include<set>
using namespace std;
int main() {
	int n;
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	set<string> s;

	cin.ignore();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		if (str == "ENTER") {
			s.clear();
		} else {
			if (s.find(str) == s.end()) {
				cnt++;
			}
			s.insert(str);
		}
	}
	cout << cnt;
	return 0;
}