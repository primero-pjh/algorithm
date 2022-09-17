#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int> v;

	unsigned long long sum = 0;

	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			v.pop_back();
		}
		else {
			v.push_back(a);
		}
	}


	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}
	printf("%llu", sum);
	return 0;
}