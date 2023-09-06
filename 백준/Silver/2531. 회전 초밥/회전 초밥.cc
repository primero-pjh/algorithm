#include <iostream>
#include <algorithm>

using namespace std;
int n, d, k, c;
int arr[70001];
int visited[3001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		arr[n + i] = arr[i];
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		int value = arr[i];
		if (visited[value] == 0) {
			ans++;
		}
		visited[value]++;
	}

	int start = 0;
	int max_value = ans;
	if (visited[c] == 0) {
		max_value++;
	}
	int end = k - 1;
	while (1) {
		if (end == n + k - 1) {
			break;
		}
		if (visited[arr[start]] == 1) {
			ans--;
		}
		visited[arr[start]]--;
		start++;
		end++;
		if (visited[arr[end]] == 0) {
			ans++;
		}
		visited[arr[end]]++;
		if (visited[c] == 0) {
			max_value = max(max_value, ans + 1);
		}
		else {
			max_value = max(max_value, ans);
		}
	}

	cout << max_value;

	return 0;
}