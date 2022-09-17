#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    
    int result = stoi(a);
    if (result < 10) {
        a = "0" + a;
    }
    bool is_progress = true;
    string start_string = a;
    int count = 1;
    while(is_progress) {

        int x = start_string[0] - '0';
        int y = start_string[1] - '0';
        string z;
        if (x + y >= 10) {
            z = to_string(x+y)[1];
        }
        else {
            z = to_string(x+y);
        }
        start_string = to_string(y) + z;
        if (start_string == a) {
            is_progress = false;
        } else {
            count++;
        }
    }
    cout << count;

    return 0;
}
