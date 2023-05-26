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
	string str1; string str2;
	cin >> n;
	set<string> s;
	int is_start = 0;
	
	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		if (str1 == "ChongChong" || str2 == "ChongChong") {
			s.insert(str1);
			s.insert(str2);
		}
		else {
			if (s.find(str1) != s.end()) {
				s.insert(str2);
			}
			if (s.find(str2) != s.end()) {
				s.insert(str1);
			}
		}
	}
	cout << s.size();
	return 0;
}