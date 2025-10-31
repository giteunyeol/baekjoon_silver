#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

#define X first 
#define Y second 

int board[302][302];
int dist[302][302];

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for(int TC = 0; TC < tc; TC++)
    {   
        //board와 dist 초기화.
        memset(board, 0, sizeof(board));
        memset(dist, -1, sizeof(dist));
        //첫줄 : 체스판 길이 n, 두번째 줄 : 나이트 현재 칸 : start, 세번째 줄 : 나이트 도착해야하는 칸 : arrive
        int n, start_x, start_y, arrive_x, arrive_y; //체스판의 크기는 n * n임.
        cin >> n >> start_x >> start_y >> arrive_x >> arrive_y;
        //시작좌표와 도착 좌표가 같은경우. 0출력 후 다음 테스트케이스로 넘어감.
        //엣지케이스
        if(start_x == arrive_x && start_y == arrive_y)
        {
            cout << '0' << '\n';
            continue;
        }

        queue <pair<int, int>> Q;
        dist[start_x][start_y] = 0;
        Q.push({start_x, start_y});
        while(!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for(int dir = 0; dir < 8; dir++)
            {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) { continue; } //체스판은 정사각혁이여서 n * n임.
                if(dist[nx][ny] >= 0) { continue; }
                // board[nx][ny]가 목적지일 경우. + 1을 더한 값을 cout후 다음 테스트케이스. 현재 있는 큐를 다 비우고 브레이크를 하면 while문을 나가니 다음 테스트케이스 실행.
                if(nx == arrive_x && ny == arrive_y) 
                {
                    cout << dist[cur.X][cur.Y] + 1 << "\n"; 
                    while(!Q.empty())
                    {
                        Q.pop();
                    }
                    break;
                }
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    
    return 0;
}
