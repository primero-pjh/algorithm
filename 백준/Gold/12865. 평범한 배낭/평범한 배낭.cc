#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> v;
int dp1[100][100000] = { 0, };
int dp2[100][100000] = { 0, };
bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		pair<int, int> p;
		scanf("%d %d", &p.first, &p.second);
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			for (int j = 1; j <= k; j++) {
				if (v[i].first <= j) {
					dp1[i][j - 1] = v[i].second;
					dp2[i][j - 1] = v[i].first;
				}
			}
		}
		else {
			for (int j = 1; j <= k; j++) {
				dp1[i][j - 1] = dp1[i - 1][j - 1];
				dp2[i][j - 1] = dp2[i - 1][j - 1];
				
				if (v[i].first <= j) {
					dp1[i][j - 1] = max(dp1[i - 1][j - 1], v[i].second);
					dp2[i][j - 1] = max(dp2[i - 1][j - 1], v[i].first);
				}
				if (j - v[i].first > 0) {
					dp1[i][j - 1] = max(v[i].second + dp1[i-1][j - v[i].first-1], dp1[i][j - 1]);
					//dp1[i][j - 1] = max(dp1[i][j - 1] + v[i].second, dp1[i][j-1]);
					//dp2[i][j - 1] = max(dp2[i][j - 1] + v[i].first, dp2[i][j-1]);
				}
			}
		}
		
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			res = max(res, dp1[i][j]);
		}
	}
	printf("%d", res);
	return 0;
}