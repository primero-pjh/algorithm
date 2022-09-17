#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;
int main()
{
    int run_count = 0;
    cin >> run_count;
    vector<vector<int>> x;
    x.clear();

    //cin.ignore();       // getline 을 쓰면 첫 번째 문제열을 삭제해서 들고온다 이때 ignore를 써줘야한다.
    for (int i = 0; i < run_count; i++) {
        vector<int> y;
        y.clear();
        int a, b;
        cin >> a >> b;
        y.push_back(a);
        y.push_back(b);
        x.push_back(y);
    }
    for (int i = 0; i < x.size(); i++) {
        int n1 = x[i][0]; int n2 = x[i][1];
        int a = 1;
        bool is_stop = true;
        for (int j = 0; j < n2; j++) {
            a = (a * n1) % 10;
        }
        if (a != 0) {
            cout << (a) << endl;
        } else {
            cout << 10 << endl;
        }
    }

    return 0;
}