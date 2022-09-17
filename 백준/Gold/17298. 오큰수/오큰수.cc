//2022-09-03
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
int N;
int arr[1000001] = { 0, };
int res[1000001] = { 0, };
stack<int> s;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a;
		scanf("%d", &a);
		arr[i] = a;
	}

	for (int i = N - 1; i >= 0; i--) {
		if (i == N - 1) {
			res[i] = -1;
			s.push(arr[i]);
		}
		else {
			if (arr[i] >= s.top()) {
				s.pop();
				while (s.empty() == false) {
					if (arr[i] < s.top()) {
						res[i] = s.top();
						s.push(arr[i]);
						break;
					}
					else {
						s.pop();
					}
				}
				if (s.empty()) {
					res[i] = -1;
					s.push(arr[i]);
				}
			}
			else {
				res[i] = s.top();
				s.push(arr[i]);
			}
			
			
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", res[i]);
	}

	return 0;
}