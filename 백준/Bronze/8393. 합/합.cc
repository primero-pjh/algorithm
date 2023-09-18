#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

typedef long long ll;
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	ll sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum;
	return 0;
}