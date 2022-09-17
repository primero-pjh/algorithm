#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
    int count = 0;
    vector<string> x;
    x.clear();              // clear 를 해줘야함. size는 삭제되나, capacity 는 삭제되지 않음 이때 shrink_to_fit()을 사용해주면 실제 크기에 맞게 설정됨.

    cin >> count;       // 실행횟수
    cin.ignore();
    for (int i = 0; i < count; i++) {   // 변수입력받음
        string a = "";
        getline(cin, a);
        x.push_back(a);
    }

    int length = x[0].length(); // 모든 값의 길이가 같으므로
    int x_count = 0;            // 
    for (int i = 0; i < length; i++) {
        char a = x[0][i];
        for (int j = 1; j < count; j++) {
            if (x[j][i] == a) {
                x_count++;
            }
        }
        if (x_count == count - 1) {
            cout << a;
        }
        else {
            cout << '?';
        }
        x_count = 0;
    }

    return 0;
}