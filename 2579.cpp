#include <iostream>
#include <algorithm>

using namespace std;

int score[301];
int memo[301];

int dp(int n)
{
    if(n == 0) {return 0;}
    if(n == 1) {return score[1];}
    if(n == 2) {return score[1] + score[2];}

    if(memo[n] != -1) {return memo[n];}

    return memo[n] = max(score[n] + dp(n-2), score[n] + score[n - 1] + dp(n-3));
}

int main(void)
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }
    fill(memo, memo+301, -1);

    cout << dp(n);

    return 0;
}