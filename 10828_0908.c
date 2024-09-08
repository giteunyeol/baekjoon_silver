//스택 구현문제

#include <stdio.h>
#include <string.h>

#define maxsize 10001

typedef struct stack
{
    int value[maxsize];
    int top;
} stack;

void createstack(stack *p)
{
    p->top = -1;
}

void push(stack *p)
{
    int number;
    scanf("%d", &number);

    p->top++;
    p->value[p->top] = number;
}

void pop(stack *p) // pop
{
    if (p->top == -1)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", p->value[p->top]);
        p->top--;
    }
}

void size(stack *p) // size
{
    printf("%d\n", p->top + 1);
}

void empty(stack *p) // empty
{
    if (p->top == -1) // 비어있는경우
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
}

void topfunc(stack *p)
{
    if (p->top == -1) // 스택이 비어있는경우
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", p->value[p->top]);
    }
}
int main(void)
{

    int n;
    int top = -1;
    scanf("%d", &n);
    stack stk;
    createstack(&stk);

    for (int i = 0; i < n; i++)
    {
        char string[20];
        scanf("%s", string);
        if (strcmp(string, "push") == 0) // push구현
        {
            push(&stk);
        }
        else if (strcmp(string, "pop") == 0) // pop구현
        {
            pop(&stk);
        }
        else if (strcmp(string, "size") == 0) // size구현
        {
            size(&stk);
        }
        else if (strcmp(string, "empty") == 0) // empty구현
        {
            empty(&stk);
        }
        else if (strcmp(string, "top") == 0) // top구현
        {
            topfunc(&stk);
        }
    }

    return 0;
}