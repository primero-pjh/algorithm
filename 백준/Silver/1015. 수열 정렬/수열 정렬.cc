// 2021-10-23
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
    int run = 0;
    cin >> run;
    vector<int> origin; origin.clear();
    vector<int> arr; arr.clear();

    for (int i = 0; i < run; i++) {
        int a = 0;
        cin >> a;
        origin.push_back(a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    map<int, vector<int>> m; m.clear();
    for (int i = 0; i < arr.size(); i++) {
        vector<int> v; 
        if (m.find(arr[i]) == m.end()) {
            m[arr[i]] = vector<int>();
        }
        m[arr[i]].push_back(i);
    }
    map<int, vector<int>>::iterator iter;

    for (int i = 0; i < origin.size(); i++) {
        cout << m[origin[i]][0] << " ";
        m[origin[i]].erase(m[origin[i]].begin());
    }


    return 0;
}