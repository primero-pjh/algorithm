// 2021-11-09
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {
	int n;
	vector<int> v; v.clear();
	while (true) {
		cin >> n;
		int count = 0;
		if (n == 0) {
			break;
		}
		if (n == 1) {
			v.push_back(1);
			continue;
		}
		int value = 0;
		for (int i = n+1; i <= 2 * n; i++) {
			count = 0;
			if (i == 1) {
				continue;
			}
			int a = (int)sqrt(i);
			for (int j = 2; j <= a; j++) {
				if (i % j == 0) {
					count++;
					break;
				}
			}
			if (count == 0) {
				value++;
			}
		}
		v.push_back(value);
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	return 0;
}