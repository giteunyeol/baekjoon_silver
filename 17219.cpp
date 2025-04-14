#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    unordered_map<string, string> account; // key값 사이트, value값 비밀번호

    for (int i = 0; i < n; i++)
    {
        string key, value;
        cin >> key >> value;

        account[key] = value; // key값에 value삽입
    }

    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        cout << account[temp] << "\n";
    }

    return 0;
}