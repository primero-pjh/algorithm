#include <stdio.h>
#include <vector>

using namespace std;

int arr[1000001] = { 0, };
vector<int> v;

void b_search(int start, int end, int x) {
	int mid = (start + end) / 2;
	//printf("[%d, %d] mid: [%d]\n", start, end, mid);
	if (start == end) {
		v[mid] = x;
		/*for (int i = 0; i < v.size(); i++) {
			printf("%d ", v[i]);
		}*/
		return;
	}
	if (x > v[mid]) {
		b_search(mid+1, end, x);
	}
	else if (x == v[mid]) {
		return;
	}
	else {
		b_search(start, mid, x);
	}

}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		//printf("i: %d, x: %d\n", i, arr[i]);
		//printf("v.size: %d\n", v.size());
		if (arr[i] > v[v.size()-1]) {
			v.push_back(arr[i]);
		}
		else if (arr[i] == v[v.size() - 1]) {
			continue;
		}
		else {
			b_search(0, v.size()-1, arr[i]);
		}
	}

	/*for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
	}*/

	printf("%d", v.size());
	return 0;
}