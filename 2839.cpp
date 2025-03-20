#include <iostream>

//dp

using namespace std;

int d[5001] = {0};

int dp(int n)
{
    if(n < 0)                return 1e9;
    if(n == 3 || n == 5)     return 1;
    if(d[n] != 0)            return d[n];
    
    return d[n] = min(dp(n-5) + 1, dp(n-3) + 1);
}

int main(void)
{
    d[3] = 1;
    d[5] = 1;

    int n; 
    cin >> n;

    dp(n);

    if(d[n] >= 1e9)
    {
        cout << "-1";
    }
    else
    {
        cout << d[n];
    }

    return 0;
}