//2021-11-13
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int cnt = 0;
void dfs(string val)
{
    cnt++;
    int sum = 0;
    for (int i = 0; i < val.size(); i++) {
        sum += (val[i] - '0');
    }
    if (sum >= 10) {
        dfs(to_string(sum));
    }
    else {
        printf("%d\n", cnt);
        if (sum % 3 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return;
    }
}

int main()
{
    string x;
    getline(cin, x);
    if (x.size() == 1) {
        int sum = stoi(x);
        cout << 0 << endl;
        if (sum % 3 == 0) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return 0;
    }
    dfs(x);
    return 0;
}