#include <iostream>
#include <algorithm>

using namespace std;


int n, m;
int cnt = 0;

int a[20001];
int b[20001];
void bs(int value) {
	int start = 0;
	int end = m - 1;
	int mid = 0;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (b[mid] < value) {
			start = mid + 1;
		}
		/*else if (b[mid] == value) {
			start = mid;
			break;
		}*/
		else if (b[mid] >= value) {
			end = mid - 1;
		}
	}

	cnt += start;
	//cout << start << ", " << end << ", " << mid << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cnt = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> b[i];
		}

		sort(b, b + m);
		for (int i = 0; i < n; i++) {
			bs(a[i]);
		}
		cout << cnt << "\n";
	}
	return 0;
}