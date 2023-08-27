#include <iostream>
#include <set>

using namespace std;

set<int> s;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		s.insert(a % 42);
	}
	cout << s.size();
	return 0;
}