#include <iostream>
#include <algorithm>

using namespace std;

//combination, 같은 총 배열 중복출력 X -> last밸류를 for문에 들어가기 전에 선언
// (1,1) , (9,9)같은 같은수 출력함. for문 i를 0부터 시작.

int n, m;
int save_numbers[10];
int arr[10];

void solve(int arr_index, int number_index)
{
    if(arr_index == m)
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    int last = 0; //0이 입력안되니까!(자연수)
    for(int i = number_index; i < n; i++)
    {
        if(last != save_numbers[i])
        {
            arr[arr_index] = save_numbers[i];
            last = save_numbers[i];
            solve(arr_index + 1, i);
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
        cin >> save_numbers[i];
    }
    sort(save_numbers, save_numbers + n);
    solve(0, 0);

    return 0;
}
