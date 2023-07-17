#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	int a = 0;
	while (getline(cin, str)) {
		a = 0;
		if (str == "#") {
			break;
		}
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
				str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
				a++;
			}
			/*else if (str[i] == ',' || str[i] == '.' || str[i] == '!' || str[i] == '?') {
				c++;
			}
			else if (str[i] != ' ') {
				b++;
			}*/
		}
		cout << a << "\n";
	}
	return 0;
}