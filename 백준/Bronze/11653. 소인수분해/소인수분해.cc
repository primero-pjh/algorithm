// 2021-11-09
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v; v.clear();
	int a = 2;
	int avg = 1;
	int first = n;
	while (true) {
		if (n % a == 0) {
			v.push_back(a);
			n = n / a;
			avg *= a;
			a = 2;
		}
		else {
			a++;
		}
		if (avg == first) {
			break;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}