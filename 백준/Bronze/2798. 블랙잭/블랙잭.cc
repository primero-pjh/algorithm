//2021-11-18
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main()
{
    int n, m;
    vector<int> v;
    cin >> n >> m;
    while (n--) {
        int a = 0;
        cin >> a;
        v.push_back(a);
    }
    map<int, bool> res; res.clear();
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                sum += (v[i] + v[j] + v[k]);
                res[sum] = true;
                sum = 0;
            }
        }
    }

    map<int, bool>::iterator iter;
    int max = 0;
    for (iter = res.begin(); iter != res.end(); iter++) {
        if (iter->first <= m) {
            max = iter->first;
        }
    }
    printf("%d ", max);

    
    return 0;
}