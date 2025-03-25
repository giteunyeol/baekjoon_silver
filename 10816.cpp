#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, number;
    cin >> n;
    unordered_map <int, int> cards;

    //number키값에 value++
    for(int i = 0; i < n; i++)
    {
        cin >> number;
        cards[number]++;
    }

    cin >> m;
    
    for(int i = 0; i < m; i++)
    {
        cin >> number;
        cout << cards[number] << " ";
    }

    return 0;
}