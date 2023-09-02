#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;

deque<char> dq;
stack<int> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int prev = 0;
	for (int i = 0; i < n; i++) {
		int a;
		char c;
		cin >> a;
		if (a == 3) {
			if (!s.empty()) {
				int top = s.top();
				if (top == 1) {
					dq.pop_back();
				}
				else if (top == 2) {
					dq.pop_front();
				}
				s.pop();
			}
		}
		else {
			cin >> c;
			if (a == 1) {
				dq.push_back(c);
			}
			else if (a==2) {
				dq.push_front(c);
			}
			s.push(a);
		}
	}
	if (dq.size() == 0) {
		cout << 0;
	}
	else {
		for (int i = 0; i < dq.size(); i++) {
			cout << dq[i];
		}
	}
	
	return 0;
}