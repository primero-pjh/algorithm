// 2021-11-11
#include<iostream>
#include<string>
using namespace std;
long long n = 0;
string str = "";
void repeat(long long a) {
	n = (a / 2);
	str = to_string(a % 2) + str;
}

int main() {
	cin >> n;
	while (true) {
		repeat(n);
		if (n == 0) {
			break;
		}
	}
	cout << str;
	return 0;
}