// 2021-11-05
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int n = 1;
	map<int, bool> m; m.clear();
	for (int i = 1; i <= 10000; i++) {
		m[i] = true;
	}

	map<int, bool>::iterator iter;
	

	for (iter = m.begin(); iter != m.end(); iter++) {
		int x = iter->first;
		for (int i = 0; i < to_string(iter->first).size(); i++) {
			x += (to_string(iter->first)[i] - '0');
		}
		if (m.find(x) != m.end()) {
			m[x] = false;
		}
	}

	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == true) {
			cout << iter->first << endl;
		}
	}


	return 0;
}