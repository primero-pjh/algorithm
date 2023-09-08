#include <iostream>
#include <algorithm>

using namespace std;

int n, k;

int s[10001];
int d[10001];
int p[10001];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}

	while (k--) {
		for (int i = 1; i <= n; i++) {
			p[d[i]] = s[i];
		}
		for (int i = 1; i <= n; i++) {
			s[i] = p[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << p[i] << " ";
	}
	return 0;
}