#include <iostream>

using namespace std;

int n, m;
int arr[10];

void solve(int k, int number) // k는 현재 배열을 몇개 채웠는지, number는 현재 수
{
    if (k == m) // basecase
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = number; i <= n; i++)
    {
        arr[k] = i;
        solve(k + 1, i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    solve(0, 1);

    return 0;
}