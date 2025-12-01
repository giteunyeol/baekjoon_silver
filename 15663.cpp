#include <iostream>
#include <algorithm>
using namespace std;

// 순열, 숫자 입력받음.
int n, m;
int input_numbers[10];
int arr[10];
bool used[10];

void solve(int cur)
{
    if(cur == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    int last = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used[i] && input_numbers[i] != last)
        {
            used[i] = true;
            arr[cur] = input_numbers[i];
            last = input_numbers[i];
            solve(cur + 1);
            used[i] = false;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> input_numbers[i];
    }
    sort(input_numbers, input_numbers + n);
    solve(0);

    return 0;
}