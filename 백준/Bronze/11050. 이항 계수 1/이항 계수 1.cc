//2021-12-09
#include<iostream>
using namespace std;

int main() {
	int x; int y;
	cin >> x >> y;
	int sum = 1;
	for (int i = 1; i <= y; i++) {
		sum *= (x-i+1);
	}

	for (int i = 1; i <= y; i++) {
		sum /= (i);
	}

	cout << sum << endl;

	return 0;
}