#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int input_numbers[10];
int arr[10];

void solve(int cur, int number_index) //배열에 몇칸까지 갔는지, 현재 input numbers의 인덱스가 어디인지
{
    if(cur == m) //base case
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = number_index; i < n; i++)
    {
        arr[cur] = input_numbers[i];
        solve(cur + 1, i);
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
    solve(0, 0);

    return 0;
}