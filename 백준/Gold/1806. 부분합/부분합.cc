#include <iostream>
#include <algorithm>

using namespace std;

int n, s, arr[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = 0;
	int result = arr[0];
	int ans = 100001;
	while (end < n) {
		if (result < s) {
			end++;
			result += arr[end];
		}
		else if (result == s) {
			ans = min(ans, (end - (start - 1)));
			//cout << start << ", " << end << ", " << ans << "\n";
			end++;
			result += arr[end];
		}
		else if (result > s) {
			ans = min(ans, (end - (start - 1)));
			result -= arr[start];
			start++;
		}
	}

	if (ans == 100001) {
		cout << 0;
	}
	else {
		cout << ans;
	}
	return 0;
}