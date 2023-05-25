#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> v1;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		v1.push_back(x);
		m[x] = 0;
	}
	int idx = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		iter->second = idx;
		idx++;
	}
	for (int i = 0; i < v1.size(); i++) {
		printf("%d ", m[v1[i]]);
	}

	return 0;
}