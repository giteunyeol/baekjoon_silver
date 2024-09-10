// 팩토리얼 0의갯수 판정

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int numbersave2 = 0;
    int numbersave5 = 0;
    // 0 / 1의 입력값이 들어온경우
    if(n == 0 || n == 1)
    {
        printf("0");
        exit(0);
    }

    for(int i = 2; i <= n ; i++) // 판정할 수 (n) -> 2까지
    {
        int temp;
        temp = i;
        while(temp % 2 == 0) 
        {
            numbersave2++;
            temp = temp / 2;
        }
        while(temp % 5 == 0)
        {
            numbersave5++;
            temp = temp / 5;
        }
    }


    // 작은 인수의 갯수를 printf
    if (numbersave2 >= numbersave5) //2의 인수의 갯수가 5의 인수의 갯수보다 많을때
    {
        printf("%d", numbersave5); // numbersave5 printf
    }
    else if (numbersave2 < numbersave5) // 5의 인수의 갯수가 2의 인수의 갯수보다 많을때
    {
        printf("%d", numbersave2);
    }

    return 0;
}