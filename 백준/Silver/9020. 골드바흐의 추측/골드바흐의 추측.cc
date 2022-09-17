// 2021-11-09
#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<string>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector<string> v; v.clear();
	vector<int> arr; arr.clear();
	map<int, int> m; m.clear();
	map<int, int>::iterator iter;
	while (t--) {
		int a = 0;
		int count = 0;
		cin >> a;
		for (int i = 2; i <= a; i++) {
			int b = (int)sqrt(i);
			for (int j = 2; j <= b; j++) {
				if (i % j == 0) {
					count++;
					break;
				}
			}
			if (count == 0) {
				arr.push_back(i);
			}
			count = 0;
		}
		for (int i = 0; i < arr.size(); i++) {
			for (int j = i; j < arr.size(); j++) {
				if (arr[i] + arr[j] == a) {
					
					m[arr[i]] = arr[j];
					if (arr[i] == arr[j]) {
						break;
					}
				}
			}
		}
		int min = 10000;
		int index = 0;
		for (iter = m.begin(); iter != m.end(); iter++) {
			if (min > (iter->second - iter->first)) {
				min = iter->second - iter->first;
				index = iter->first;
			}
		}
		v.push_back(to_string(index) + " " + to_string(m[index]));
		arr.clear();
		m.clear();
	}

	for (int i = 0; i < v.size(); i++) {
		printf("%s\n", v[i].c_str());
	}

	return 0;
}