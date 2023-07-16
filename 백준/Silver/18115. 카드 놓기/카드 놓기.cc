#include <iostream>
#include <deque>
using namespace std;

int arr[1000000];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	deque<int> q;
	deque<int>::iterator it = q.begin();
	int begin_idx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		int type = arr[i];
		int idx = n - i;
		if (type == 1) {
			q.push_back(idx);
		}
		else if (type == 2) {
			if (!q.empty()) {
				q.insert(q.end() - 1, idx);
			}
			else {
				q.push_back(idx);
			}
		}
		else if (type == 3) {
			q.push_front(idx);
		}
	}

	for (auto iter = q.rbegin(); iter != q.rend(); iter++) {
		cout << *iter << " ";
	}
	cout << "\n";
	return 0;
}