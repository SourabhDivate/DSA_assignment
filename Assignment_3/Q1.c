#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int *arr;
    int top;
    int SIZE;
}stack_t;

void stack_init(stack_t *st)
{
    st->arr = (int *)malloc(sizeof(int) * st->SIZE);
    st->top = st->SIZE;
}

int stack_isEmpty(stack_t *st)
{
    return st->top == st->SIZE;
}

int stack_isFull(stack_t *st)
{
    return st->top == -1;
}

void stack_push(stack_t *st, int value)
{
    if(st->top == -1)
    {
        printf("stack is full\n");
    }
    else
    {
        st->top--;
        st->arr[st->top] = value;
    }
}

int stack_pop(stack_t *st)
{
    int temp = -1;
    if(st->top == st->SIZE)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp = st->arr[st->top];
        st->top++;
    }
    return temp;
}

int stack_peek(stack_t *st)
{
    int temp = -1;
    if(st->top == st->SIZE)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp = st->arr[st->top];
    }
    return temp;
}

int main()
{
    stack_t st;
    int size, choice, value;

    printf("Enter stack size : ");
    scanf("%d",&st.SIZE);

    stack_init(&st);

    do{
        printf("1. Push\n2. Pop\n3. Peek\n");
        printf("Enter choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to push\n");
                scanf("%d",&value);
                stack_push(&st, value);
                break;
            case 2:
                printf("poped element : %d\n",stack_pop(&st));
                break;
            case 3:
                printf("Peeked value : %d\n",stack_peek(&st));
                break;
        }

    }while (choice != 0);
    

    return 0;
}