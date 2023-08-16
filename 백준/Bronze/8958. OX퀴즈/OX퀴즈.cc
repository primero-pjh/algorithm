#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int arr[101];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		char prev = str[0];
		arr[0] = (prev == 'O' ? 1 : 0);
		for (int j = 1; j < str.size(); j++) {
			if (str[j] == 'O') {
				arr[j] = arr[j-1] + 1;
			}
			else {
				arr[j] = 0;
			}
		}
		int sum = 0;
		for (int i = 0; i < str.size(); i++) {
			sum += arr[i];
		}
		cout << sum << "\n";
	}
	return 0;
}