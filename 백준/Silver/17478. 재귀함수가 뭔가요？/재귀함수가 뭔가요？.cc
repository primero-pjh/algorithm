//2022-08-19
#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int n = 0;

void dfs(string str, int idx) {
    if (idx == 0) {
        return;
    }
    cout << str;
    printf("\"재귀함수가 뭔가요?\"\n");
    if (idx == 1) {
        return;
    }
    else {
        cout << str;
        printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
        cout << str;
        printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
        cout << str;
        printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
    }
    idx--;
    str += "____";
    dfs(str, idx);
    if (idx == 1) {
        cout << str;
        printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
    }
    cout << str;
    printf("라고 답변하였지.\n");
}

int main()
{
    scanf("%d", &n);

    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    dfs("", n + 1);
    printf("라고 답변하였지.\n");

    return 0;
}