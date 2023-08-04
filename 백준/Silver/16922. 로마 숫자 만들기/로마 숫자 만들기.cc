#include <iostream>
#include <set>
#include <map>

using namespace std;

set<int> s;
map<char, int> m;
map<char, int> visited;

int n;
int ans = 0;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= n; k++) {
				for (int q = 0; q <= n; q++) {
					if (i + j + k + q != n) { continue; }
					int cnt = (i * 1) + (j * 5) + (k * 10) + (q * 50);
					if (s.find(cnt) == s.end()) {
						ans++;
						s.insert(cnt);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}