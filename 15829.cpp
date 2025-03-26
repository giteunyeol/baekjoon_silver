#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str;
    long long ans = 0;
    long long r = 31;
    long long mod = 1234567891;
    long long power = 1;

    cin >> n >> str;

    for (int i = 0; i < n; i++)
    {
        int value = str[i] - 'a' + 1;
        ans = (ans + value * power) % mod;
        power = (power * r) % mod;
    }

    cout << ans << "\n";
    return 0;
}
