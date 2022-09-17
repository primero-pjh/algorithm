//2021-12-11
#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;
map<string, int> m;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		m.clear();
		int len;
		cin >> len;
		while (len--) {
			string x; string y;
			cin >> x >> y;
			if (m.find(y) == m.end()) {
				m[y] = 0;
			}
			if (m.find(y) != m.end()) {
				m[y]++;
			}
		}
		map<string, int>::iterator iter;
		int sum = 1;
		for (iter = m.begin(); iter != m.end(); iter++) {
			sum *= (iter->second + 1);
		}
		cout << (sum - 1) << endl;
		
	}
	
	return 0;
}