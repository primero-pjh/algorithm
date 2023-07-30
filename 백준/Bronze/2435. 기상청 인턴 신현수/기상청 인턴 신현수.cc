#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ull;

ull v[101];
ull dp[101];
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		v[i] = a;
		dp[i] = dp[i - 1] + v[i];
	}
	ull sum = 0;
	ull max_value = -99999999999;
	for (int i = k; i <= n; i++) {
		sum = dp[i] - dp[i - k];
		max_value = max(max_value, sum);
	}

	cout << max_value;
	return 0;
}