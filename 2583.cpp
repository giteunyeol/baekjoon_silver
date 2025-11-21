#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[102][102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, k; // m이 행, n이 열
    cin >> m >> n >> k;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = 1;
        }
    }

    // board와 vis은 0으로 모두 초기화된 상태.
    int start_x, start_y, finish_x, finish_y;

    // 색칠된 곳들을 모두 0으로 칠해서 빈 공간을 갈 수 있게 함.
    for (int i = 0; i < k; i++)
    {
        cin >> start_x >> start_y >> finish_x >> finish_y;
        for (int j = start_y; j < finish_y; j++)
        {
            for (int k = start_x; k < finish_x; k++)
            {
                board[j][k] = 0;
            }
        }
    }

    int area_count = 0; // 지역의 갯수를 셀 변수
    vector<int> area;   // 각 지역의 넓이

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && board[i][j] == 1) // vis[i][j]에 방문하지 않았고(0이거나) 방문해야하는 보드판이면
            {
                area_count++;
                int cur_surface = 0;
                // 0,0 -> n, m까지 bfs
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty())
                {
                    cur_surface++;
                    pair<int, int> cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if (nx < 0 || nx >= m || ny < 0 || ny >= n)
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
                area.push_back(cur_surface);
            }
        }
    }
    sort(area.begin(), area.end());
    cout << area_count << "\n";
    for(auto i : area)
    {
        cout << i << " ";
    }

    return 0;
}