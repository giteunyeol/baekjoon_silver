#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
vector<int> graph[MAX];
bool visited[MAX] = {false};
int virus_sum = -1;

void DFS(int node)
{
    visited[node] = true; // bollean타입 변환
    virus_sum++;

    //DFS
    for(int i = 0; i < graph[node].size(); i++)
    {
        int next = graph[node][i];
        if(visited[next] == false)
        {
            DFS(next);
        }
    }

}

int main(void)
{
    int PC, edge;
    cin >> PC >> edge;

    //양방향 그래프 입력
    for(int i =0; i < edge; i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    DFS(1);
    cout << virus_sum;

    return 0;
}