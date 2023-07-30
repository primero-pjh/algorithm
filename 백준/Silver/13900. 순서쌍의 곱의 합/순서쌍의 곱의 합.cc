#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;

vector<ull> v;
ull dp[100001];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
		if (i == 0) {
			dp[i] = a;
		}
		else {
			dp[i] = dp[i - 1] + v[i];
		}
	}
	ull sum = 0;
	for (int i = 0; i < n - 1; i++) {
		sum += (v[i]) * (dp[n - 1] - dp[i]);
	}

	cout << sum;
	return 0;
}