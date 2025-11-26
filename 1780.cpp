#include <iostream>

using namespace std;

int board[2200][2200]; // 숫자 담을 보드

int count_minus_one;
int count_zero;
int count_one;

bool same_number(int r, int c, int width) // 같은 숫자인지 판별하는 함수
{
    int cur_number = board[r][c];
    for(int i = r; i < r + width; i++)
    {
        for(int j = c; j < c + width; j++)
        {
            if(cur_number != board[i][j]) { return false; } // 순회하면서 다른 숫자가 있다면. 같은 숫자인가?를 false 리턴.
        }
    }
    return true; // 순회를 다 통과하면 true를 리턴.
}

void solve(int r, int c, int width) 
{
    //base case
    if(same_number(r, c, width) == true) // 현재 width * width가 같은 수 인경우
    {
        if(board[r][c] == -1) { count_minus_one++; }
        else if(board[r][c] == 0) { count_zero++; }
        else { count_one++; } // else인 경우는 1인경우니까 count_zero++;
        return;
    }

    int next_width = width / 3; // 더 작아질 한 변의 길이
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            solve(r + next_width * i, c + next_width * j, next_width);
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

    // 재귀함수가 받아야 하는 정보 << 한변의 길이, 좌표 r, 좌표 c
    solve(0, 0, n); // 0, 0, 한변의 길이 n으로 시작.
    cout << count_minus_one << "\n" << count_zero << "\n" << count_one;
    return 0;
}