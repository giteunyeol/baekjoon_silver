#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n,m;
    cin >> n >> m;
    vector<int> number(n + 1, 0);
    vector<int> prefix_sum(n + 1, 0);

    for(int i = 1; i <= n ; i++) 
    {
        cin >> number[i];
    }

    //누적합에 넣기
    for(int i = 1; i <= n; i++)
    {
        prefix_sum[i] = prefix_sum[i - 1] + number[i];
    }

    for(int i = 0; i < m; i++)
    {
        int start, finish;
        cin >> start >> finish;
        cout << prefix_sum[finish] - prefix_sum[start - 1] << "\n";
    }

    return 0;
}