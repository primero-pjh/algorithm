#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp1[100001];
int dp2[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	/*dp1[1] = 1;
	dp2[1] = 1;*/
	for (int i = 1; i <= n; i++) {
		if (arr[i - 1] >= arr[i]) {
			dp1[i] = dp1[i - 1] + 1;
		}
		else {
			dp1[i] = 1;
		}

		if (arr[i - 1] <= arr[i]) {
			dp2[i] = dp2[i - 1] + 1;
		}
		else {
			dp2[i] = 1;
		}
	}

	int max_value = 0;
	for (int i = 1; i <= n; i++) {
		max_value = max(max_value, max(dp1[i], dp2[i]));
	}
	cout << max_value;
	return 0;

}