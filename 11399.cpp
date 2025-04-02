#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int array[1001];
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        array[i] = temp;
    }

    sort(array, array+n);

    int result = 0;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum += array[i];
        result += sum;
    }

    cout << result;

    return 0;
}