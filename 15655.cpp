#include <iostream>
#include <algorithm>

using namespace std;

int save_number[10];
int arr[10];
int n, m;

void solve(int cur, int cur_number)
{
    if(cur == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    for(int i = cur_number; i < n; i++)
    {
        arr[cur] = save_number[i];
        solve(cur + 1, i + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> save_number[i];
    }
    sort(save_number, save_number + n);
    solve(0, 0);

    return 0;
}