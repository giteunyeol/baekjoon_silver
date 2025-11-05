#include <iostream>

using namespace std;

long long rec(long long a, long long b, long long c)
{
    if (b == 0) // basecase
    {
        return 1;
    }
    long long value = rec(a, b / 2, c);
    value = value * value % c;
    if (b % 2 == 0) // 짝수인 경우
    {
        return value;
    }
    else// 홀수인 경우
    {
        return value * a % c;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long a, b, c; // a: 밑, b:제곱, c: 나눠줄 수(mod)
    cin >> a >> b >> c;
    cout << rec(a, b, c);
    return 0;
}