// 2021-12-08
#include<iostream>
#include<vector>
using namespace std;

int ggc(int x, int y) {
	int r = x % y;
	if (r == 0) {
		return y;
	}
	else {
		return ggc(y, r);
	}
}

int main() {
	int x; int y;
	cin >> x >> y;
	int a = (x > y) ? x : y;
	int b = (x > y) ? y : x;

	int xy = ggc(a, b);
	cout << xy << endl;
	cout << (a / xy) * b << endl;
	
	return 0;
}