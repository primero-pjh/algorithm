#include <iostream>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

deque<int> dq;
stack<int> s;
int arr[1001] = { 0, };
int n;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dq.push_back(arr[i]);
	}
	int idx = 1;
	while (!dq.empty()) {
		if (dq.front() != idx) {
			s.push(dq.front());
			dq.pop_front();
		}
		else {
			idx++;
			dq.pop_front();
			while (!s.empty()) {
				if (s.top() == idx) {
					s.pop();
					idx++;
				}
				else {
					break;
				}
			}
		}
	}
	while (!s.empty()) {
		if (s.top() == idx) {
			s.pop();
			idx++;
		}
		else {
			cout << "Sad";
			exit(0);
		}
	}

	cout << "Nice";
	return 0;
}