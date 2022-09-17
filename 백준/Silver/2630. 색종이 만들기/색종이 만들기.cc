//2021-11-13
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

vector<vector<char>> v;
int one_cnt = 0;
int zero_cnt = 0;

void dfs(int a, int b, int size)
{
    int first = v[a][b];
    int fail = 0;
    for (int i = a; i < size+a; i++) {
        for (int j = b; j < b+size; j++) {
            if (first == v[i][j]) {
                continue;
            }
            else {
                fail++;
                break;
            }
        }
    }
    if (fail > 0) {
        dfs(a, b, size / 2);
        dfs(a + (size / 2), b , size / 2);
        dfs(a, b + (size / 2), size / 2);
        dfs(a + (size / 2), b + (size / 2), size / 2);
    }
    else {
        if (first == '1') {
            one_cnt++;
        }
        else {
            zero_cnt++;
        }
        return;
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char a;
        vector<char> c; c.clear();
        for (int j = 0; j < n; j++) {
            cin >> a;
            c.push_back(a);
        }
        v.push_back(c);
    }
    

    int first = v[0][0];
    int fail = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (first == v[i][j]) {
                continue;
            }
            else {
                fail++;
                break;
            }
        }
    }
    if (fail > 0) {
        dfs(0, 0, n/2);
        dfs(0, n/2, n/2);
        dfs(n/2, 0, n/2);
        dfs(n/2, n/2, n/2);

        cout << zero_cnt << endl;
        cout << one_cnt << endl;
        return 0;
    }
    else {
        if (first == '1') {
            one_cnt += 1;
        }
        else {
            zero_cnt += 1;
        }
        cout << zero_cnt << endl;
        cout << one_cnt << endl;
    }
    return 0;
}