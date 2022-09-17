#include<iostream>
#include<string>
#include<vector>
#include<map>
//#include<sstream>
using namespace std;

int main()
{
    int count;
    cin >> count;

    int index = 1;
    int x = 1;
    int y = 1;

    int time = 1;
    if (count == 1) {
        cout << to_string(x) + "/" + to_string(y) << endl;
        return 0;
    }
    bool is_y = true;
    while (true) {
        if (is_y) {
            y++;
        }
        else {
            x++;
        }

        time += 1;
        if (time == count) {
            cout << to_string(x) + "/" + to_string(y) << endl;
            return 0;
        }
        for (int i = 0; i < index; i++) {
            if (is_y) {
                y--;
                x++;
            }
            else {
                x--;
                y++;
            }

            time += 1;
            if (time == count) {
                cout << to_string(x) + "/" + to_string(y) << endl;
                return 0;
            }
        }
        index++;
        is_y = is_y == true ? false : true;
    }
    cout << to_string(x) + "/" + to_string(y) << endl;

    return 0;
}