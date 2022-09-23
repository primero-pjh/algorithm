#include <iostream>
#include<string>
#include<map>

using namespace std;

map<string, int> m;
map<string, int> res;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		m[str] = 0;
	}

	int cnt = 0;
	for (int i = 0; i < k; i++) {
		string str;
		cin >> str;
		if (m.find(str) != m.end()) {
			cnt++;
			res[str] = 0;
		}
	}
	printf("%d\n", cnt);
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		cout << iter->first << endl;
	}
	return 0;
}