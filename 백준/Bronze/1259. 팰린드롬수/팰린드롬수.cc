#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    vector<string> v;
    v.clear();
    while (true) {
        string a = "";
        getline(cin, a);
        if (a == "0") {
            break;
        }
        v.push_back(a);
    }
    
    for (int i = 0; i < v.size(); i++) {
        if (v[i].length() == 1) {
            cout << "yes" << endl;
            continue;
        }
        int a = 0;
        int z = v[i].length() - 1; 

        if (v[i].length() % 2 == 0) {   // 짝수
            while (true) {
                if (v[i][a] == v[i][z]) {

                }
                else {
                    cout << "no" << endl;
                    break;
                }
                a++;
                z--;
                if (z - a < 0) {
                    cout << "yes" << endl;
                    break;
                }
            }
        }
        else {  // 홀수
            while (true) {
                if (v[i][a] == v[i][z]) {

                }
                else {
                    cout << "no" << endl;
                    break;
                }
                a++;
                z--;
                if (z == a) {
                    cout << "yes" << endl;
                    break;
                }
            }
        }
        
    }
    return 0;
}