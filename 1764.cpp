#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    int count = 0;
    unordered_map <string, int> name; // key값을 이름, value값을 Int로해서 카운트
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        name[temp]++;  //temp의 key값을 가진곳에 ++
    }

    for(int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        name[temp]++;
        if(name[temp] == 2)
        {
            count++;
        }
    }
    
    cout << count << "\n";

    vector <string> result;
    
    for(auto it = name.begin(); it != name.end(); ++it)
    {
        if(it->second == 2)
        {
            result.push_back(it->first);
        }
    }

    sort(result.begin(), result.end());
    
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}