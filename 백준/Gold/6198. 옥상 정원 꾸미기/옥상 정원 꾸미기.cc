#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

long long sum = 0;
int n;
stack<int> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int h;
		cin >> h;
		if (s.empty()) {
			s.push(h);
		}
		else {
			if (s.top() > h) {
				sum += s.size();
				s.push(h);
			}
			else {
				while (!s.empty()) {
					if (s.top() <= h) {
						s.pop();
					}
					else {
						break;
					}
				}
				sum += s.size();
				s.push(h);
			}
		}
	}
	cout << sum;
	return 0;
}