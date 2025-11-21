#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dist[2000002];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int finish, start, goal, up, down;
    cin >> finish >> start >> goal >> up >> down;
    if(start == goal)
    {
        cout << 0;
        return 0;
    }
    queue<int> Q;
    //start에서 시작, dist는 모두 0으로 초기화돼있음.
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;
    Q.push(start);
    int move[2] = {up, -down}; // up만큼 증가하고 down만큼 내려가
    while(!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 2; dir++)
        {
            int nx = cur + move[dir];
            if(nx < 1 || nx > finish) { continue; } // 음수로 가버리거나 끝점을 넘어가버린 경우
            if(dist[nx] >= 0) { continue; } // 방문한 경우
            if(nx == goal) // 목표도착시 출력 후 프로그램 종료
            {
                cout << dist[cur] + 1;
                return 0;
            }
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    //큐를 다 돌았는데 없었음. 그러면 use the stiars
    cout << "use the stairs";
    return 0;
}