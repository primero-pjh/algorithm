#include <iostream>
#include <vector>

using namespace std;

int n, m;
int min_value = 0;
int res[100001] = { 0, };
int arr[100001] = { 0, };
vector<int> v;

void reset_res() {
	for (int i = 0; i <= n; i++) {
		res[i] = 0;
	}
}
void bs() {
	int start = 0;
	int end = n - 1;
	int height = 0;

	while (start <= end) {
		reset_res();
		height = (start + end) / 2;
		int prev_x = arr[0] - height;
		int prev_y = arr[0] + height;
		if (prev_x < 0) { prev_x = 0; }
		if (prev_y > n) { prev_y = n; }
		bool is_complete = true;
		for (int i = 1; i < m; i++) {
			int x = arr[i] - height;
			int y = arr[i] + height;
			if (x < 0) { x = 0; }
			if (y > n) { y = n; }
			if (x > prev_y) {
				is_complete = false;
				break;
			}
			else {
				prev_x = x;
				prev_y = y;
			}
		}
		if (is_complete && arr[0] - height <= 0 && prev_y >= n) {
			min_value = min(min_value, height);
			end = height - 1;
		}
		else {
			start = height + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
	}
	min_value = n;
	bs();
	cout << min_value << "\n";

	return 0;
}