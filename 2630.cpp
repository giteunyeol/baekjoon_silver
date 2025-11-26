#include <iostream>

using namespace std;

int board[130][130]; // board : 130개

int numbers[2]; // 0,1인덱스에 각각 갯수 저장

bool same_number(int r, int c, int width) //현재 판별할곳이 모두 같은 수인지
{
    int cur_number = board[r][c]; // 현재 사각형에서 제일 좌상 숫자를 cur_number로 지정.
    for(int i = r; i < r + width; i++)
    {
        for(int j = c; j < c + width; j++)
        {
            if(cur_number != board[i][j]) // 다르면 false 리턴
            return false;
        }
    }
    //모두 순회했는데 판별이 안되면 true 리턴.
    return true;
}

void solve(int r, int c, int width) // 좌표: (r,c), width:현재 한 변의 길이
{
    if(same_number(r, c, width)) //true가 나오면.
    {
        numbers[board[r][c]] = numbers[board[r][c]] + 1; // board[r][c]의 수를 numbers의 인덱스++
        return; // 더 나눌필요 없으니 리턴.
    }
    else // false가 나오면
    {
        int next_width = width / 2; // 1/4로 계속 나눠지니까.
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                solve(r + next_width * i, c + next_width * j, next_width);
            }
        }
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
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    solve(0, 0, n);
    cout << numbers[0] << "\n" << numbers[1];

    return 0;
}