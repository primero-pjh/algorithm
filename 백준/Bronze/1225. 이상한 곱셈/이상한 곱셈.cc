#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    string s1;
    string s2;
    cin >> s1 >> s2;
    long result = 0;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            result = result + ((s1[i] - '0') * (s2[j] - '0'));
        }
    }
    cout << result;
    return 0;
}
