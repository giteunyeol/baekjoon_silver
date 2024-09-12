#include <stdio.h>

#define maxsize 100001

typedef struct stack
{
    int top;
    int number[maxsize];
}stack;

void makestack(stack * p)
{

    p -> top = -1;

}

void pop(stack * p)
{
    p->top--;
}

void push(stack * p, int command)
{
    p->top++;
    p->number[p->top] = command; 
}

void sum(stack * p)
{
    int answer = 0;
    for(int i = 0; i <= p->top; i++)
    {
        answer += p->number[i];
    }
    
    printf("%d", answer);
}

//스택으로 구현

 int main(void)
 {
    int n;
    scanf("%d", &n);

    stack stk;
    makestack(&stk);


    for(int i = 0; i < n; i++) // n번만큼 명령어 실행
    {
        int command;
        scanf("%d", &command);
        if(command == 0) // 스택에서 가장 최근 수 삭제(pop)
        {
            pop(&stk);
        }
        else // 스택에 수 삽입(push) , sum에 숫자 더하기
        {
            push(&stk, command);
        }
    }

    sum(&stk);

    return 0;
 }