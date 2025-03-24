#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;

    cin >> n;
    vector <int> arr(n); //arr
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    //sort 후 binary search

    sort(arr.begin(), arr.end());

    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        int i_want_go_home = binary_search(arr.begin(), arr.end(), temp);

        if(i_want_go_home == true) //있을경우
        {
            cout << "1\n";
        }
        else
        {
            cout << "0\n";
        }
    }

    return 0;
}