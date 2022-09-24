#include <iostream>
#include<string>
#include<map>

using namespace std;

map<int, int> m1;
map<int, int> m2;
map<int, int> res;
int main() {
	int n, k;
	int cnt = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		m1[a] = 0;
	}

	for (int i = 0; i < k; i++) {
		int a;
		scanf("%d", &a);
		m2[a] = 0;
		if (m1.find(a) != m1.end()) {
			cnt++;
		}
	}

	printf("%d", (n + k) - (cnt * 2));
	return 0;
}