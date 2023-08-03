#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long long num)
{
	if (num <= 1)
		return false;

	if (num == 2 || num == 3)
		return true;

	if (num % 2 == 0 || num % 3 == 0)
		return false;

	for (long long i = 5; i * i <= num; ++i)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}

	return true;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		while (!isPrime(n))
			n++;
		cout << n << endl;
	}
	return 0;
}