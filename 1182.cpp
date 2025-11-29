#include <iostream>

using namespace std;

int n,s, ans = 0, numbers[25];

void solve(int cur,int sum)
{
    if(cur == n) //끝까지 도착했을때
    {
        if(sum == s) { ans++; } //합과 s가 같다면 ans++
        return;
    }
    solve(cur + 1, sum); // 현재 상태의 수를 더하지 않는경우
    solve(cur + 1, sum + numbers[cur]); // 현재 상태의 수를 더하는 경우
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s; //n은 정수의 갯수, s는 합
    for(int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    solve(0, 0);
    if(s == 0) {ans--;}
    cout << ans;
    return 0;
}