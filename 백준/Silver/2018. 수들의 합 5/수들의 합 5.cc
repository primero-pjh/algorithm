#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;
int n;
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int cnt = 0;
	int idx = 0;

	int start = 1;
	int end = 1;
	int result = 1;
	while (end <= n) {
		
		if (result < n) {
			end++;
			result += end;
		}
		else if (result == n) {
			//cout << start << ", " << end << "\n";
			cnt++;
			end++;
			result += end;
		}
		else if (result > n) {
			result -= start;
			start++;
		}
	}
	
	cout << cnt << "\n";
	return 0;

}