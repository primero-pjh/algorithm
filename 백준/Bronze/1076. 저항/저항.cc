// 2021-10-21 ~ 2021-10-21
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <cmath> //C++
//#include<sstream>

using namespace std;

int main()
{
    int count = 3;
    map<string, vector<long long>> m;
    vector<long long> x;
    x.clear();
    vector<string> y;
    y.clear();
    x.push_back(0);
    x.push_back(1);
    m["black"] = x;
    x.clear();
    vector<string> color = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" };
    for (int i = 1; i < 10; i++) {
        x.push_back(i);
        x.push_back(pow(10,i));
        m[color[i]] = x;
        x.clear();
    }

    for (int i = 0; i < count; i++) {
        string a;
        getline(cin, a);
        y.push_back(a);
    }

    long long result;
    long long fv = 0;
    fv = m[y[0]][0] * 10 + m[y[1]][0];
    result = m[y[2]][1] * fv;
    cout << result << endl;

    return 0;
}
