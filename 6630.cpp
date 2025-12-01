#include <iostream>
#include <algorithm>

using namespace std;

int numbers[15];
int arr[15];
int n;

void solve(int cur_index, int start)
{
    if(cur_index == 6)
    {
        for(int i = 0; i < 6; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = start; i < n; i++)
    {
        arr[cur_index] = numbers[i];
        solve(cur_index + 1, i + 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true)
    {
        cin >> n;
        if(n == 0) { break; }
        for(int i = 0; i < n; i++)
        {
            cin >> numbers[i];
        }
        sort(numbers, numbers + n);

        solve(0, 0);
        cout << "\n";
    }

    return 0;
}