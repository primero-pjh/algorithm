//2021-11-20
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n;
vector<vector<int>> v;
vector<int> res;
void dfs(int idx, vector<int> arr)
{
    if (arr.size() == n/2) {
        
        map<int, bool> m;
        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] = true;
        }
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (m.find(i) != m.end()) {
                a.push_back(i);
            }
            else {
                b.push_back(i);
            }
        }

        int a_sum = 0;
        int b_sum = 0;

        for (int i = 0; i < a.size(); i++) {
            for (int j = i + 1; j < a.size(); j++) {
                a_sum += v[a[i]][a[j]] + v[a[j]][a[i]];
                b_sum += v[b[i]][b[j]] + v[b[j]][b[i]];
                
            }
        }
        int sum = abs(a_sum - b_sum);
        res.push_back(sum);

        return;
    }
    for (int i = idx+1; i < n; i++) {
        arr.push_back(i);
        dfs(i, arr);
        arr.pop_back();
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> a; a.clear();
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        v.push_back(a);
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }*/

    for (int i = 0; i < n; i++) {
        vector<int> arr;
        arr.push_back(i);
        dfs(i, arr);
        arr.pop_back();
    }

    int min = 100;
    for (int i = 0; i < res.size(); i++) {
        if (min > res[i]) {
            min = res[i];
        }
    }
    cout << min << endl;
    return 0;
}