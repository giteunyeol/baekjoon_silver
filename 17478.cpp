#include <iostream>

using namespace std;

int n;

void under_bar(int cur, const char* str) //cur가 현재 몇번 재귀를 들어갔는지, str이 현재 스트링
{
    for(int i = 0; i < cur; i++)
    {
        cout << "____";
    }
    cout << str << "\n";
}

void rec(int cur)
{
    under_bar(cur, "\"재귀함수가 뭔가요?\"");
    if(cur == n) // cur가 n까지 들어갔을때
    {
        under_bar(cur, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
    }
    else // cur가 n까지 남은 경우 
    {
        under_bar(cur, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
        under_bar(cur, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
        under_bar(cur, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
        rec(cur + 1);
    }
    under_bar(cur, "라고 답변하였지.");
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << "\n";
    rec(0);
}