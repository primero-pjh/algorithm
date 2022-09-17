//2021-11-08
#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n = 0; 
	cin >> n;
	int a = n / 5;
	if (n % 5 == 0) {
		cout << n / 5 << endl;
		return 0;
	}
	for (int i = a; i >= 1; i--) {
		if ((n - (5 * i)) % 3 == 0) {
			cout << ((n - (5 * i)) / 3 ) + i << endl;
			return 0;
		}
	}
	if (n % 3 == 0) {
		cout << n / 3 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}