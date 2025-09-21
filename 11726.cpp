#include <iostream>
#include <algorithm>

using namespace std;

int memo[1001];
const int moduler = 10007;

int dp(int n)
{
    if(n == 1) { return 1; }
    if(n == 2) { return 2; }   

    if(memo[n] != -1) { return memo[n]; }

    return memo[n] = (dp(n - 1) + dp(n - 2)) % moduler;
}

int main(void)
{
    int n;
    cin >> n;
    fill(memo, memo + 1001, -1);
    cout << dp(n);
    return 0;
}