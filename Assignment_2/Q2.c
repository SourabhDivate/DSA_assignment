#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int *arr;
    int front, rear;
    int SIZE;
}queue_t;

void init_queue(queue_t *q, int size)
{
    q->SIZE = size;
    q->arr = (int *)malloc(sizeof(int) * size);
    q->front = q->rear = 0;
}

void push_queue(queue_t *q, int value)
{
    if(q->rear == q->SIZE)
    {
        printf("Queue is full\n");
    }
    else
    {
        q->arr[q->rear] = value;
        q->rear++;
    }
}

int peek_queue(queue_t *q)
{
    int temp = -1;
    if(q->rear == q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = q->arr[q->front];
    }
    return temp;
}

int pop_queue(queue_t *q)
{
    int temp = -1;
    if(q->rear == q->front)
    {
        printf("Queue is empty\n");
    }
    else
    {
        temp = q->arr[q->front];
        q->front++;
    }
    return temp;
}

int isEmpty_queue(queue_t *q)
{
    return q->rear == q->front;
}

int isFull_queue(queue_t *q)
{
    return q->rear == q->SIZE;
}

int main()
{
    queue_t q;
    int size, choice, value;

    printf("Enter size of queue : ");
    scanf("%d",&size);

    init_queue(&q, size);

    do
    {
        printf("1. Push\n2. Peek\n3. Pop\nEnter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to be pushed : ");
                scanf("%d",&value);
                push_queue(&q, value);
                break;
            case 2:
                printf("Peeked data is : %d\n",peek_queue(&q));
                break;
            case 3:
                printf("Poped data is %d\n",pop_queue(&q));
                break;
        }
    } while (choice != 0);
    

    return 0;
}