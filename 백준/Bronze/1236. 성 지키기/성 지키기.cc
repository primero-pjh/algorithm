#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int col;
    int row;
    cin >> col >> row;
    cin.ignore();
    vector<string> v;
    v.clear();
    for (int i = 0; i < col; i++) {
        string a = "";
        getline(cin, a);
        v.push_back(a);
    }
    int count = 0;
    int x_result = 0;
    int y_result = 0;
    vector<char> is_unique;
    is_unique.clear();
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            if (v[i][j] == 'X') {
                count++;
            }
        }
        if (count == 0) {
            x_result++;
        }
        count = 0;
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (v[j][i] == 'X') {
                count++;
            }
        }
        if (count == 0) {
            y_result++;
        }
        count = 0;
    }
    cout << ((x_result > y_result) ? x_result : y_result) << endl;
}