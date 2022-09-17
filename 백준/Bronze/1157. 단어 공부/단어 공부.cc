#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    string x;
    getline(cin, x);
    map<char, long> m;
    m.clear();
    for (long i = 0; i < x.length(); i++) {
        x[i] = toupper(x[i]);
        if (m.find(x[i]) == m.end()) {
            m[x[i]] = 0;
        }
        if (m.find(x[i]) != m.end()) {
            m[x[i]]++;
        }
    }

    map<char, long>::iterator iter;
    long a = m.begin()->second;
    char b = m.begin()->first;
    long count = 0;
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (a < iter->second) {
            a = iter->second;
            b = iter->first;
        }
    }
    for (iter = m.begin(); iter != m.end(); iter++) {
        if (a == iter->second) {
            count++;
        }
    }
    if (count > 1) {
        cout << "?" << endl;
    }
    else {
        cout << b << endl;
    }

    return 0;
}