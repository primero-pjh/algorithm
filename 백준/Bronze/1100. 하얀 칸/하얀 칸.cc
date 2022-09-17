#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int count = 8;
    vector<string> x;
    x.clear();
    int result = 0;
    for (int i = 0; i < count; i++) {
        string a = "";
        getline(cin, a);
        x.push_back(a);
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count; j++) {
            if (x[i][j] == 'F') {
                if (i % 2 == 0) 
                {
                    if (j % 2 == 0) {
                        result++;
                    }
                }
                else 
                {
                    if (j % 2 == 1) {
                        result++;
                    }
                }
            }
        }
    }
    cout << result;

    return 0;
}