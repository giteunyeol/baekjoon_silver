#include <iostream> 
#include <algorithm>

using namespace std;

int input_numbers[10]; //처음에 입력받을 변수
int arr[10]; //숫자들을 저장할 배열
bool used[10]; //숫자가 아니라 인덱스로 판별함.
int n, m; //n은 배열의 크기, m은 몇개 고르는지

void solve(int cur)
{
    if(cur == m)//base case
    {
        for(int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            arr[cur] = input_numbers[i];
            used[i] = true;
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