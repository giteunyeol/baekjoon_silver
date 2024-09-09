// 큐 구현


#include <stdio.h>
#include <string.h>

#define maxsize 10001

typedef struct queue
{
    int front;
    int rear;
    int numbers[maxsize];
} queue;

void createqueue(queue *que)
{
    que -> front = -1;
    que -> rear = -1;
}

void push(queue * p)
{
    int number;
    scanf("%d", &number);
    p->front++;
    p->numbers[p->front] = number;
}

void pop(queue * p)   ////////////// 여기만 수정
{
    if(p-> front == p -> rear) //큐가 비었을때
    {
        printf("-1\n");
    }
    else // pop을 실행할때
    {
        printf("%d\n", p->numbers[p->rear + 1]);
        p->rear++;
    }
}

void size(queue * p)
{
    if(p->rear == -1)
    {
        printf("%d\n", p->front + 1);
    }
    else if(p->front == p->rear)
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n", p->front - p-> rear);
    }
}

void empty(queue * p)
{
    if(p-> front == p -> rear) // queue가 빈 경우
    {
        printf("1\n");
    }
    else // queue가 차있는경우
    {
        printf("0\n");
    }
}

void front(queue * p)
{
    if(p-> front == p -> rear) // queue가 빈경우
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", p -> numbers[p->rear + 1]); 
    }
}

void back(queue * p)
{
    if(p->front == p-> rear) // queue가 빈경우
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", p->numbers[p->front]);
    }
    
}



int main(void)
{
    queue que;
    createqueue(&que);

    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char string[20];
        scanf("%s", string);

        if (strcmp(string, "push") == 0) // push 구현
        {
            push(&que);
        }
        else if (strcmp(string, "pop") == 0) // pop 구현
        {
            pop(&que);
        }
        else if (strcmp(string, "size") == 0) // size 구현
        {
            size(&que);
        }
        else if (strcmp(string, "empty") == 0) // empty 구현
        {
            empty(&que);
        }
        else if (strcmp(string, "front") == 0) // front 구현
        {
            front(&que);
        }
        else if (strcmp(string, "back") == 0) // back 구현
        {
            back(&que);
        }
    }

    return 0;
}