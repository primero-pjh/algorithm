#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> v;
int arr[500001] = { 0, };
int res[500001] = { 0, };
stack<pair<int, int>> s;
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			pair<int, int> p;
			p.first = arr[i];
			p.second = i;
			s.push(p);
		}
		else {
			if (s.top().first < arr[i]) {
				s.pop();
				while (!s.empty()) {
					if (s.top().first > arr[i]) {
						break;
					}
					else {
						s.pop();
					}
				}
				if (!s.empty()) {
					res[i] = s.top().second;
				}
			}
			else {
				res[i] = s.top().second;
			}
			pair<int, int> p;
			p.first = arr[i];
			p.second = i;
			s.push(p);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}

	return 0;
}