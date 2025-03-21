#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector <int> arr(n);

    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}