#include <iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v; v.clear();
	v.push_back(0);
	v.push_back(1);

	int run = 0;
	cin >> run;
	for (int i = 1; i < 21; i++) {
		v.push_back(v[i] + v[i - 1]);
	}

	cout << v[run];
	return 0;
}