#include <iostream>
#include <algorithm>

using namespace std;

int dp_save[1000001];

int dp(int n)
{
    if(n == 1)
    {
        return 0;
    }
    
    if(dp_save[n] != -1)
    {
        return dp_save[n];
    }
    
    int value = dp(n - 1) + 1; //가장 안좋은 기본설정

    if(n % 2 == 0) //2로 나누어 떨어질때
    {
        value = min(value, dp(n / 2) + 1);
    }
    
    if(n % 3 == 0)
    {
        value = min(value, dp(n/3) + 1);
    }
    
    dp_save[n] = value;
    return value;

}

int main(void)
{
    int n;
    cin >> n;
    fill(dp_save, dp_save + 1000001, -1);
    cout << dp(n);

    return 0;
}