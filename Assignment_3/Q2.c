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
    st->top = -1;
}

int stack_isEmpty(stack_t *st)
{
    return st->top == -1;
}

int stack_isFull(stack_t *st)
{
    return st->top == st->SIZE-1;
}

void stack_push(stack_t *st, int value)
{
    if(st->top == st->SIZE-1)
    {
        printf("stack is full\n");
    }
    else
    {
        st->top++;
        st->arr[st->top] = value;
    }
}

int stack_pop(stack_t *st)
{
    int temp = -1;
    if(st->top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        temp = st->arr[st->top];
        st->top--;
    }
    return temp;
}

int stack_peek(stack_t *st)
{
    int temp = -1;
    if(st->top == -1)
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
    int size, choice, value, i;

    int arr[5] = {11,22,33,44,55};

    printf("Enter stack size : ");
    scanf("%d",&st.SIZE);

    stack_init(&st);

    //do{
      //  printf("1. Push\n2. Pop\n3. Peek\n");
        //printf("Enter choice : ");
        //scanf("%d",&choice);
        //switch(choice)
        //{
          //  case 1:
               // printf("Enter value to push\n");
               // scanf("%d",&value);
                for(i=0 ; i<5 ; i++)
                {
                    stack_push(&st, arr[i]);
                }
              //  break;
            //case 2:
                //printf("poped element : %d\n",stack_pop(&st));
                for(i = 0 ; i<5 ; i++)
                {
                    printf("%-4d",stack_pop(&st));
                } 
                printf("\n");
                //break;
            //case 3:
              //  printf("Peeked value : %d\n",stack_peek(&st));
                //break;
       // }

  //  }while (choice != 0);
    

    return 0;
}