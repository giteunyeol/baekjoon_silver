#include <iostream>

using namespace std;

int arr[10]; // array
bool used[10];

void solve(int cur, int n, int m) // solve는 백트래킹 상태를 왔다갔다함.
{
    if(cur == m) // 배열이 다 차면
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(!used[i]) //사용 안한 수가 있다면
        {
            used[i] = true;
            arr[cur] = i;
            solve(cur + 1, n, m);
            used[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; //n은 숫자의 범위. 1 ~ n 까지. m은 배열의 길이.
    
    cin >> n >> m;

    solve(0, n, m);

    return 0;
}  