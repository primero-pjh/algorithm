#include <stdio.h>
#include <map>
using namespace std;

unsigned long long arr[1000001] = { 0, };
unsigned long long dp[1000001] = { 0, };
unsigned long long dp2[1000001] = { 0, };
unsigned long long dp3[1000001] = { 0, };
map<int, unsigned long long> m;
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}

	dp[0] = arr[0];
	dp2[0] = arr[0] % M;
	dp3[0] = 0;
	dp3[1] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = arr[i] + dp[i - 1];
	}
	for (int i = 1; i < 1000001; i++) {
		dp3[i] = dp3[i - 1] + (i);
	}
	

	for (int i = 0; i < N; i++) {
		dp2[i] = dp[i] % M;
	}

	unsigned long long count = 0;
	for (int i = 0; i < N; i++) {
		if (dp2[i] == 0) {
			count++;
		}
		if (m.find(dp2[i]) == m.end()) {
			m[dp2[i]] = 0;
		}
		if (m.find(dp2[i]) != m.end()) {
			m[dp2[i]] = m[dp2[i]] + 1;
		}
	}

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		count += dp3[iter->second-1];
	}
	printf("%llu", count);
	return 0;

}