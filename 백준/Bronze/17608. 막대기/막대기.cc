#include <iostream>
#include <string>
#include <map>
#include <stack>

using namespace std;

map<int, int> graph;
int arr[100001];
stack<int> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	s.push(arr[n-1]);
	for (int i = n - 2; i >= 0; i--) {
		if (s.top() < arr[i]) {
			s.push(arr[i]);
		}
	}
	cout << s.size();
	return 0;
}