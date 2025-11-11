#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, word_length; // n: 보드판의 크기, k : 단어의 길이
        cin >> n >> word_length;
        int board[32][32]; // n * n인데 편의상 그냥 32 * 32로 생성.
        memset(board, 0, sizeof(board)); // 외부는 0으로 초기화.
        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp;
                cin >> temp;
                board[i][j] = temp;
            }
        }

        // 더도말고 덜도 말고 딱 n칸 후 끝나야함. ex) k : 2면, wwb처럼 두칸 후 블랙이 와야함. 1이 화이트, 0이 블랙
        for (int i = 0; i < n ; i++)
        {
            for (int j = 0; j < n ; j++)
            {
                int boolean = true;
                // 가로부터. 현재 board[i][j]에 있음.
                for (int k = j; k < j + word_length; k++) // 가로 순회
                {
                    if (board[i][k] == 0) // 블랙이면(단어가 끊기면)
                    {
                        boolean = false;
                        break;
                    }
                }
                if (board[i][j + word_length] == 1) // 만약 다음이 마지막 다음이화이트면, false
                {
                    boolean = false;
                }
                if(j != 0) // 좌측 끝이 아닐때
                {
                    if(board[i][j - 1] == 1)
                    {
                        boolean = false;
                    }
                }
                // 위의 검출코드를 통과했다면 , answer ++;
                if (boolean == true)
                {
                    answer++;
                }

                boolean = true;                           // 초기화
                for (int k = i; k < i + word_length; k++) // 세로 순회
                {
                    if (board[k][j] == 0) // 블랙이면
                    {
                        boolean = false;
                        break;
                    }
                }
                if(board[i + word_length][j] == 1)
                {
                    boolean = false;
                }
                if(i != 0) // 상단 끝이 아닐때
                {
                    if(board[i - 1][j] == 1)
                    {
                        boolean = false;
                    }
                }
                if(boolean == true)
                {
                    answer++;
                }
            }
        }
        
        cout << '#' << t << " " << answer << "\n";
    }

    return 0;
}