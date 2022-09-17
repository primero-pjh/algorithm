#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int a = abs(w - x);
    int b = abs(h - y);

    vector<int> result;
    result.clear();
    result.push_back(x);
    result.push_back(y);
    result.push_back(a);
    result.push_back(b);

    int m = result[0];
    for (int i = 0; i < result.size(); i++) {
        if (m > result[i]) {
            m = result[i];
        }
    }
    cout << m;
}