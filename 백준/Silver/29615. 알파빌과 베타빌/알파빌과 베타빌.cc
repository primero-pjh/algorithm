#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int arr[1001];
bool fri[1001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		fri[a] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (i < m) {
			if (fri[arr[i]] == 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}