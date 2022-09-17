//2022-01-04
#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;
vector<int> res;
int main() {
	int n;
	cin >> n;
    cin.ignore();
    while (n--) {
        string str = "";
        string cmd = "";
        getline(cin, str);
        vector<string> x; x.clear();
        if (str.find("push") != string::npos) {
            istringstream ss(str);
            string stringBuffer;
            while (getline(ss, stringBuffer, ' ')) {
                x.push_back(stringBuffer);
            }
            cmd = x[0];
        }
        else {
            cmd = str;
        }

        if (cmd == "push") {
            res.push_back(stoi(x[1]));
        }
        else if (cmd == "pop") {
            if (res.size() == 0) {
                printf("%d\n", -1);
            }
            else {
                int a = res[res.size()-1];
                printf("%d\n", a);
                res.pop_back();
            }
        }
        else if (cmd == "size") {
            printf("%d\n", res.size());
        }
        else if (cmd == "empty") {
            if (res.size() == 0) {
                printf("%d\n", 1);
            }
            else {
                printf("%d\n", 0);
            }
        }
        else if (cmd == "top") {
            if (res.size() == 0) {
                printf("%d\n", -1);
            }
            else {
                printf("%d\n", res[res.size() -1]);
            }
        }
    }
	return 0;
}