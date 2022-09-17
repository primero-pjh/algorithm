//2021-11-06
#include<iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	int count = 1;

	long long x = 1;
	long long start = 6;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	while (true) {
		if (n <= x) {
			cout << count << endl;
			break;
		}
		x += start;
		start += 6;
		count++;
	}

	return 0;
}