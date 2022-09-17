// 2021-10-24
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
    int n, run;
    cin >> n >> run;

    vector<int> package; package.clear();
    vector<int> piece; piece.clear();


    for (int i = 0; i < run; i++) {
        int a, b;
        cin >> a >> b;
        package.push_back(a);
        piece.push_back(b);
    }

    int min_package = package[0];
    int min_piece = piece[0];

    for (int i = 0; i < package.size(); i++) {
        if (min_package > package[i]) {
            min_package = package[i];
        }
    }
    for (int i = 0; i < piece.size(); i++) {
        if (min_piece > piece[i]) {
            min_piece = piece[i];
        }
    }
    int result1 = 0;
    int result2 = 0;
    int result3 = 0;
    
    int a = n / 6;
    int b = n - (6 * a);

    result1 = (a * min_package) + (b * min_piece);
    result2 = (min_package * (a+1));
    result3 = (min_piece * n);
    cout << (result1 > result2 ? (result2 > result3 ? result3 : result2) : (result1 > result3 ? result3 : result1)) << endl;
    return 0;
}