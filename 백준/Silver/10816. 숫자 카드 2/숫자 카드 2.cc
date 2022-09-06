// 2022-09-06
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;
int arr1[500001] = { 0 };
int arr2[500001] = { 0 };
int res[500001] = { 0 };

map<int, int> m;
int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (m.find(a) == m.end()) {
			m[a] = 0;
		}
		if (m.find(a) != m.end()) {
			m[a]++;
		}
	}

	int M;
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a;
		scanf("%d", &a);
		if (m.find(a) != m.end()) {
			printf("%d ", m[a]);
		}
		else {
			printf("%d ", 0);
		}
	}


	return 0;
}