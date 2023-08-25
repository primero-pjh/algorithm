#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
int arr[21];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, j;
	cin >> n >> m;
	cin >> j;
	for (int i = 0; i < j; i++) {
		cin >> arr[i];
	}
	int start = 1;
	int end = m;
	int ans = 0;
	for (int i = 0; i < j; i++) {
		if (arr[i] >= start && arr[i] <= end) {
			continue;
		}
		else if(arr[i] < start) {
			start--;
			end--;
			ans++;
			while (start > 0) {
				if (arr[i] >= start && arr[i] <= end) {
					break;
				}
				start--;
				end--;
				ans++;
			}
		}
		else if (arr[i] > end) {
			start++;
			end++;
			ans++;
			while (end <= n) {
				if (arr[i] >= start && arr[i] <= end) {
					break;
				}
				start++;
				end++;
				ans++;
			}
		}
	}
	cout << ans;

	return 0;
}