#include <map>
#include <stdio.h>
using namespace std;

int arr1[500000] = { 0, };
int arr2[500000] = { 0, };
map<int, int> m1;
map<int, int> m2;
int main() {
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr1[i]);
		m1[arr1[i]] = 0;
	}

	int m;
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &arr2[i]);
	}

	for (int i = 0; i < m; i++) {
		if (m1.find(arr2[i]) != m1.end()) {
			printf("%d ", 1);
		}
		else {
			printf("%d ", 0);
		}
	}

	return 0;
}