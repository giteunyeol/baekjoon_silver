#include <iostream>
#include <algorithm>

using namespace std;

int memo[41]; //memo를 -1로 채움

int fib(int n)
{

    if (n == 0){ return 0; }
    if (n == 1){ return 1; }

    if(memo[n] != -1) { return memo[n]; }

    return memo[n] =  fib(n-1) + fib(n-2);
}

int main(void)
{
    int n;
    cin >> n;
    fill(memo, memo + 41, -1);
    for(int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        if(number == 0) { cout << "1" << " " << 0 << "\n"; continue;}
        cout << fib(number - 1) << " " << fib(number) << "\n";
    }

    return 0;
}