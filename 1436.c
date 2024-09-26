//숫자에 666이 포함 되어있는 n번째 숫자를 찾는 알고리즘 (브루트포스)

#include <stdio.h>

int main(void)
{
    int n;
    int count = 0;
    scanf("%d", &n);
    int distinction = 665;

    while (count < n)
    {
        distinction++;
        int temp = distinction;

        while(temp != 0) // temp가 0이되면 루프 종료
        {
            if(temp % 1000 == 666) // temp가 666포함
            {
                count++;
                break;
            }
            temp = temp / 10;
        }
    } 

    printf("%d", distinction);

    return 0;
}