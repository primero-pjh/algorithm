//2021-11-06
#include<iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a == c) {
		cout << 1 << endl;
		return 0;
	}
	
	if ((c - a) % (a - b) == 0) {
		cout << (c - a) / (a - b) + 1 << endl;
	}
	else {
		cout << (c - a) / (a - b) + 2 << endl;
	}
	return 0;
}