#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int save_numbers[10];
int arr[10];

void solve(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        arr[cur] = save_numbers[i];
        solve(cur + 1);
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> save_numbers[i];
    }
    sort(save_numbers, save_numbers + n);
    solve(0);

    return 0;
}
