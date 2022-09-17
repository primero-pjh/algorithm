// 2021-10-29
#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	int count = 0;
	if (N >= 10) {
		count = 9;
	}
	else {
		count = N;
	}
	while (true) {
		for (int i = N; i >= 10; i--) {
			string a = to_string(i);
			int wrong = 0;
			int x = (a[0] -'0') - (a[1]-'0');
			for (int j = 0; j < a.size() - 1; j++) {
				if (a[j] - a[j + 1] != x) {
					wrong++;
				}
			}
			if (wrong > 0) {
				continue;
			}
			count++;
		}
		break;
	}
	cout << count << endl;
	
	return 0;
}