#include <iostream>
#include <cstring>

using namespace std;

string board[64];

bool same_number(int r, int c, int width)
{
    char cur_number = board[r][c];
    for(int i = r; i < r + width; i++)
    {
        for(int j = c; j < c + width; j++)
        {
            if(cur_number != board[i][j]) { return false; } // 현재 다른 숫자가 있다면 false 리턴.
        }
    }
    //다 순회했는데 넘어오면 true 리턴
    return true;
}
void solve(int r, int c, int width) 
{
    if(same_number(r, c, width)) // 현재 다 같은 숫자들이면.
    { 
        cout << board[r][c];
        return;
    }
    cout << '(';
    if (!same_number(r, c, width)) // 다른 숫자가 검출 된다면
    {
        int next_width = width / 2;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                solve(r + i * next_width, c + j * next_width, next_width);
            }
        }
        cout << ')';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    solve(0, 0, n);

    return 0;
}