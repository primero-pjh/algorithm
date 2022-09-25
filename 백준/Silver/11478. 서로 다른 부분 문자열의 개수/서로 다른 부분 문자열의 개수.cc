//22.09.25
#include <iostream>
#include<string>
#include<map>

using namespace std;


int main() {
	string str;
	cin >> str;
	map<string, int> m;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		string a; 
		for (int j = i; j < len; j++) {
			a += str[j];
			if (m.find(a) == m.end()) {
				m[a];
			}
		}
	}
	
	printf("%d", m.size());
	return 0;
}