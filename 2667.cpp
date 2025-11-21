#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define X first 
#define Y second 

string board[30];
bool vis[30][30];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> houses;
    int houses_count = 0;
    for(int i = 0 ; i < n; i++) // 입력받음
    {
        cin >> board[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) //하나씩 bfs
        {
            if(!vis[i][j] && board[i][j] == '1') // 방문하지 않았고 board[i][j]가 1일때
            {
                houses_count++; // 단지갯수 ++
                //bfs를 돌림.
                int count = 0; // 여기가 이번 i,j에서 bfs를 돌린 결과를 카운트해줄 변수
                queue<pair<int, int>> Q;
                vis[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty())
                {
                    count++;
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; }
                        if(vis[nx][ny]|| board[nx][ny] != '1') { continue; } // 방문
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                //bfs가 다 돌아가면 벡터에 삽입함
                houses.push_back(count);
            }
        }
    }
    
    cout << houses_count << "\n";
    sort(houses.begin(), houses.end());
    for(auto i : houses)
    {
        cout << i << "\n";
    }
    
}