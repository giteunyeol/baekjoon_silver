#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define X first
#define Y second

int board[502][502];
int vis[502][502];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int count = 0;
    int surface = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            queue<pair<int, int>> Q;
            if(vis[i][j] || board[i][j] != 1) { continue; }
            count++;
            vis[i][j] = 1;
            Q.push({i, j});

            int temp_surface = 0;
            while (!Q.empty())
            {
                pair<int, int> cur = Q.front();
                temp_surface++;
                Q.pop();
                for (int dir = 0; dir < 4; dir++)
                {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx > n || ny < 0 || ny > m)
                    {
                        continue;
                    }
                    if (vis[nx][ny] || board[nx][ny] != 1)
                    {
                        continue;
                    }
                    vis[nx][ny] = 1;
                    Q.push({nx, ny});
                }
            }
            surface = max(surface, temp_surface);
        }
    }

    cout << count << "\n" << surface;

    return 0;
}