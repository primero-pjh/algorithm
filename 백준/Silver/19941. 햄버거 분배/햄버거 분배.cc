#include <iostream>
#include <algorithm>

using namespace std;

bool visited[20000];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'P') {
			int x = i - k;
			int y = i + k;
			int cnt = 0;
			if (x < 0) { x = 0; }
			if (y >= n) { y = n - 1; }
			for (int j = x; j <= y; j++) {
				if (str[j] == 'H' && visited[j] == 0) {
					visited[j] = 1;
					cnt++;
					break;
				}
			}
			if (cnt > 0) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}
