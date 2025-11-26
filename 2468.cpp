#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

#define X first 
#define Y second 

int board[102][102];
bool vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

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

    //max값을 찾아야함.
    int max_water_height = board[0][0];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            max_water_height = max(max_water_height, board[i][j]);
        }
    }
    
    int ans = 1; // 아무 지역도 잠기지 않는 경우. 답 1
    for(int cur_height = 1; cur_height < max_water_height; cur_height++)
    {
        memset(vis, 0, sizeof(vis));
        int cur_ans = 0; //현재 답
        //좌표마다 bfs
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j] && board[i][j] > cur_height) //방문하지 않았고, board[i][j]의 높이가 cur_height보다 높을때 bfs.
                {
                    //bfs를 돌때마다 cur_ans++;
                    cur_ans++;
                    //현재 bfs의 시작 좌표: I, J;
                    queue<pair<int, int>> Q;
                    vis[i][j] = true;
                    Q.push({i, j});
                    while(!Q.empty())
                    {
                        pair <int, int> cur = Q.front(); Q.pop();
                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.X + dx[dir];
                            int ny = cur.Y + dy[dir];
                            if(nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
                            if(vis[nx][ny] || board[nx][ny] <= cur_height) { continue; } // 방문한곳이면 continue;
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
        ans = max(ans, cur_ans); // 현재 물 수면에서 답과 토탈 답중에 맥스값을 비교해서 판별.
    }

    cout << ans;

    return 0;
}