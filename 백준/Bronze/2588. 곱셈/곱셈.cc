//22.09.25
#include <iostream>
#include<string>
#include<map>

using namespace std;


int main() {
	string str1;
	int a;
	scanf("%d", &a);
	cin >> str1;
	int c = stoi(str1);
	for (int i = str1.size() - 1; i >= 0; i--) {
		int b = 0;
		b = a * (str1[i] - '0');
		printf("%d\n", b);
	}
	printf("%d", a * c);
	return 0;
}