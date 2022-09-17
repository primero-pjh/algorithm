// 2021-10-26
#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<algorithm>
//#include<cmath>
//#include<sstream>
using namespace std;

int main()
{
    int run;
    cin >> run;
    vector <int> v; v.clear();

    v.push_back(1);
    v.push_back(2);


    for (int i = 1; i < run; i++) {
        //cout << v[i] << " ";
        v.push_back(((v[i]) + (v[i - 1])) % 10007);
    }

    cout << v[run-1];
    

    return 0;
}