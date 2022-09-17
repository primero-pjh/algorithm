#include <iostream>

using namespace std;

int main() {
	unsigned long long N, L;
	cin >> N >> L;
	
	if (N % 2 == 0 && L == 2) {
		L++;
	}

	while (true) {
		long x, y;
		x = 0;
		y = 0;
		if (L > 100) {
			cout << -1 << endl;
			return 0;
		}
		long count = L - 1;
		if (L%2 == 1) {
			if (N%L != 0) {
				L += 1;
				continue;
			}
			else {
				int main = N / L;
				long x = 0;
				long y = 0;
				long index = 1;
				while (true) {
					x = main - index;
					if (x < 0) {
						L++;
						break;
					}
					y = main + index;
					long sum = 0;
					for (int i = x; i <= y; i++) {
						sum += i;
					}
					
					if (sum == N) {
						for (int i = x; i <= y; i++) {
							cout << i << " ";
						}
						return 0;
					}
					index++;
				}
			}
		}
		else {
			int main = N / L;
			x = main - ( N % L ) + 1;
			if (x < 0) {
			}
			else {
				long sum = 0;
				for (int i = x; i < L + x; i++) {
					sum += i;
				}
				if (sum == N) {
					for (int i = x; i < L + x; i++) {
						cout << i << " ";
					}
					return 0;
				}
			}
			L++;
		}
	}


	return 0;
}