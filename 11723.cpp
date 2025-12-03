#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int check;
    cin >> check;
    bool s[21];
    fill(s, s + 21, 0);

    for(int i = 0; i < check; i++)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "all")
        {
            fill(s, s + 21, 1);
            continue;
        }
        else if(cmd == "empty")
        {
            fill(s, s + 21, 0);
            continue;
        }

        int x;
        cin >> x;
        if(cmd == "add")
        {
            s[x] = 1;
        }
        else if(cmd == "remove")
        {
            s[x] = 0;
        }
        else if(cmd == "check")
        {
            cout << s[x] << "\n";
        }
        else if(cmd == "toggle")
        {
            if(s[x] == 1) { s[x] = 0; }
            else { s[x] = 1; }
        }
        else if(cmd == "all")
        {
            fill(s, s + 21, 1);
        }
    }

    return 0;
}