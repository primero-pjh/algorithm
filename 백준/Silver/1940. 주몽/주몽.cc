#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[15001];
bool visited[15001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int start = 0;
	int end = n - 1;
	int ans = 0;
	while (start < end) {
		//cout << start << ", " << end << "\n";
		if (arr[start] + arr[end] > m) {
			end--;
		} else if (arr[start] + arr[end] == m) {
			start++;
			end--;
			ans++;
		}
		else {
			start++;
		}
	}

	cout << ans;
	return 0;
}