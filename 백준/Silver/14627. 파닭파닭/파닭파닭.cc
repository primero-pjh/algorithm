#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ull;
int s, c;
ull arr[1000001];
ull max_value = 0;
ull res = 0;
void bs() {
	ull start = 1;
	ull end = max_value;
	ull mid = 0;
	
	while (start <= end) {
		ull cnt = 0;
		mid = (start + end) / 2;
		//cout << start << " " << end << " " << mid << "\n";
		for (int i = 0; i < s; i++) {
			cnt += (arr[i] / mid);
		}
		if (cnt > c) {
			start = mid + 1;
		}
		else if (cnt == c) {
			start = mid + 1;
		}
		else if (cnt < c) {
			end = mid - 1;
		}
	}
	max_value = end;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> c;
	for (int i = 0; i < s; i++) {
		cin >> arr[i];
		max_value = max(max_value, arr[i]);
	}
	bs();

	//cout << "max_value: " << max_value << "\n";
	ull ans = 0;
	int cnt = 0;
	int idx = 0;
	while (cnt < c) {
		if (arr[idx] - max_value >= 0) {
			arr[idx] -= max_value;
			cnt++;
		}
		if(arr[idx] - max_value < 0) {
			idx++;
		}
	}
	for (int i = 0; i < s; i++) {
		ans += arr[i];
	}
	cout << ans << "\n";
	return 0;
}
