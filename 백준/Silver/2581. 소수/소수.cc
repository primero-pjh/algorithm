// 2021-11-09
#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int m, n;
	cin >> m;
	cin >> n;
	int sum = 0;
	int min = n;
	for (int i = m; i <= n; i++) {
		if (i == 1) {
			continue;
		}
		int x = (int)sqrt(i);
		int count = 0;
		for (int j = 2; j <= x; j++) {
			if (i % j == 0) {
				count++;
			}
		}
		if (count == 0) {
			sum += i;
			if (min > i) {
				min = i;
			}
		}
	}
	if (sum == 0) {
		cout << -1 << endl;
		return 0;
	}
	cout << sum << endl;
	cout << min << endl;
	return 0;
}