#include <iostream>
#include <algorithm>

using namespace std;

int arr[10];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    fill(arr, arr + 10, 1);
    for(int i = 0; i < m; i++)
    {
        arr[i] = 0;
    }

    do{
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 0)
            {
                cout << i + 1 << " ";
            }
        }
        cout << "\n";
    }while(next_permutation(arr, arr + n));

    return 0;
}