// 2021-11-09
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;


int main()
{
    int a, b, c;
    vector<string> v; v.clear();
    vector<int> arr; arr.clear();
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        arr.push_back(a);
        arr.push_back(b);
        arr.push_back(c);
        sort(arr.begin(), arr.end());
        
        if (pow(arr[0], 2) + pow(arr[1], 2) == pow(arr[2], 2)) {
            v.push_back("right");
        }
        else {
            v.push_back("wrong");
        }
        arr.clear();
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}