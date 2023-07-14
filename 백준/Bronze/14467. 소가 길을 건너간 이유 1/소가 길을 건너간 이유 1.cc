#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int arr[101];
map<int, int> m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (m.find(a) == m.end()) {
			m[a] = b;
		}
		else {
			if (m[a] != b) {
				cnt++;
				m[a] = b;
			}
		}
	}
	cout << cnt << "\n";
}