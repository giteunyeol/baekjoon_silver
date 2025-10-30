#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define X first
#define Y second

int board[52][52];
int vis[52][52];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        memset(board, 0, sizeof(board));
        memset(vis, 0, sizeof(vis));
        int n, m, k;
        cin >> m >> n >> k;
        int ans = 0;
        // n : 행 길이, m : 열 길이, k : 좌표를 받을 횟수
        // 좌표 입력받아서 1로 대체
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && board[i][j] == 1) // 방문한 경우가 없고, board가 1이면 bfs를 돌림.
                {
                    queue<pair<int, int>> Q; 
                    vis[i][j] = 1;
                    Q.push({i, j});
                    while(!Q.empty())
                    {
                        pair<int, int> cur = Q.front();
                        Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) { continue; }
                            if(vis[nx][ny] || board[nx][ny] != 1) { continue; }
                            vis[nx][ny] = 1;
                            Q.push({nx, ny});
                        }
                    }
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}