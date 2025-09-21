#include <iostream> 
#include <algorithm>

using namespace std;

int memo[11];

int dp(int n)
{
    if(n == 1) { return 1;}
    if(n == 2) { return 2;}
    if(n == 3) { return 4;}

    if(memo[n] != -1 ) { return memo[n]; }

    return memo[n] = dp(n - 1) + dp(n - 2) + dp(n - 3); 
}

int main(void)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        fill(memo, memo + 11, -1);
        int number;
        cin >> number;
        cout << dp(number) << "\n";
    }

    return 0;
}