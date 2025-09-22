#include <iostream>
#include <algorithm>

using namespace std;

long long memo[101];

long long dp(int n)
{
    //basecase
    if(n == 0) { return 1 ;}
    if(n == 1) { return 1 ;}
    if(n == 2) { return 1 ;}
    //memozation
    if(memo[n] != -1 ) { return memo[n]; }

    //dp
    return memo[n] = dp(n -2) + dp(n - 3);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int TestCase;
    cin >> TestCase;

    fill(memo, memo + 101, -1);

    for(int i = 0; i < TestCase; i++)
    {
        int n;
        cin >> n;
        //if(n == 0) {cout << "1" << "\n"; continue;}. n이 1부터 입력받기때문에 안넣어도됨
        cout << dp(n - 1) << "\n"; // 인덱스 0을 1로 간주해서 n-1해줌.
    }

    return 0;
}