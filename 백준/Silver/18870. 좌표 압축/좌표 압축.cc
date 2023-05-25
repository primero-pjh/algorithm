#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
int arr[1000001];
int main() {
	int n;
	scanf("%d", &n);
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		m[arr[i]] = 0;
	}
	int idx = 0;
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		iter->second = idx;
		idx++;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", m[arr[i]]);
	}

	return 0;
}