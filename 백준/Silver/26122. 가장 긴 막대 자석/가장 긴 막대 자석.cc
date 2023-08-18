#include <iostream>
#include <algorithm>

using namespace std;

int max_value;
int arr[300001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	char prev = str[0];
	int cnt = 1;
	bool is_cnt = false;
	for (int i = 1; i < n; i++) {
		if (str[i] != str[i - 1]) {
			arr[i]++;
		}
		else {
			if (arr[i - 1] <= 0) {
				continue;
			}
			int idx = (2 * (arr[i - 1] + 1) - 1);
			if (i - idx >= 0) {
				if (str[i - idx] != str[i]) {
					arr[i] = arr[i - 1] + 1;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		max_value = max(max_value, arr[i]);
		//cout << arr[i];
	}
	cout << max_value * 2;
	
	return 0;
}