#include<iostream>
using namespace std;

int gcd(int a, int b) {
	int r = a % b;
	if (r == 0) {
		return b;
	}
	else {
		return gcd(b, r);
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int x; int y;
		cin >> x >> y;
		int xy = gcd(x, y);

		int sum = (x > y) ? (x / xy) * y : (y / xy) * x;
		cout << sum << endl;
	}
	
	return 0;
}