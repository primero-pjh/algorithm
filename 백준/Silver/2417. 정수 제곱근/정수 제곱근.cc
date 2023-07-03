#include <iostream>
#include <math.h>
#include <climits>

using namespace std;

unsigned long long n;
unsigned long long max = ULLONG_MAX;

void binary_search(unsigned long long start, unsigned long long end) {
	unsigned long long mid = (start + end) / 2;
	unsigned long long result = sqrt(mid);
	if (mid < n) {

	}
}

// 9223372030926249000
int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	unsigned long long mod2 = sqrt(n);
	unsigned long long result = (mod2 * mod2);
			
	if (result < n) {
		cout << mod2 + 1 << "\n";
	}
	else {
		cout << mod2 << "\n";
	}
	//cout << result << "\n";
	//binary_search(0, max);
	return 0;
}