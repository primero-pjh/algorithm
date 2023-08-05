#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;
int n, h, t;
priority_queue<int> q;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	int cnt = 0;
	while (cnt < t) {
		if (q.top() == 1) {
			break;
		}
		if (q.top() < h) {
			cout << "YES\n" << cnt;
			exit(0);
		}
		else {
			int top = q.top();
			//cout << "top: " << top << "\n";
			top /= 2;
			q.pop();
			q.push(top);
			cnt++;
		}
	}

	if (q.top() < h) {
		cout << "YES\n" << cnt;
	}
	else {
		cout << "NO\n" << q.top();
	}
	return 0;
}