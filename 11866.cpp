#include <iostream>
#include <queue>

using namespace std;

// 요세푸스 문제

int main(void)
{
    int n, k;
    cin >> n >> k;

    queue<int> que;

    for (int i = 0; i < n; i++)
    {
        que.push(i + 1);
    }

    cout << "<" ;
    while (que.size() != 0) // 크기가 0일때까지 무한루프
    {
        for (int i = 0; i < k - 1; i++) // k - 1(규칙 횟수 만큼 뒤로 넘겨줌)
        {
            que.push(que.front()); // 앞에있던 숫자 삽입
            que.pop();
        }
        cout << que.front();
        que.pop();

        if(que.size() != 0)
        {
            cout << ", ";
        }
    }
    cout << ">" << "\n";

    return 0;
}