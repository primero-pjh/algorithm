// 2021-12-08
#include<iostream>
#include<vector>
using namespace std;


int main() {
	unsigned long long n;
	cin >> n;
	vector<unsigned long long> x;
	vector<unsigned long long> y;
	for (int i = 0; i < n-1; i++) {
		unsigned long long a;
		cin >> a;
		x.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		unsigned long long a;
		cin >> a;
		y.push_back(a);
	}
	
	unsigned long long min = y[0];
	for (int i = 0; i < n - 1; i++) {
		if (min > y[i]) {
			
			min = y[i];
		}
		else {
			y[i] = min;
		}
	}
	bool is_p = false;
	unsigned long long sum = 0;
	for (int i = 0; i < n - 1; i++) {
		if (min == y[i]) {
			is_p = true;
		}
		if (is_p) {
			sum = sum + (min * x[i]);
		}
		else {
			sum = sum + (x[i] * y[i]);
		}
	}

	printf("%d ", sum);

	return 0;
}