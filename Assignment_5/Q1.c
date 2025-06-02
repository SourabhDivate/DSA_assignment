#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

typedef struct list{
    node_t *tail;
}list_t;

void init_list(list_t *list)
{
    list->tail = NULL;
}

void display_list(list_t *list)
{
    if(list->tail == NULL)
    {
        return;
    }
    else
    {
        node_t *trav = list->tail->next;
        do
        {
            printf("%-4d", trav->data);
            trav = trav->next;
        } while (trav != list->tail->next);       
    }
}

node_t *create_node(int value)
{
    node_t *newnode = (node_t *)malloc(sizeof(node_t));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void add_first(list_t *list, int value)
{
    node_t *newnode = create_node(value);
    if(list->tail == NULL)
    {
        list->tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = list->tail->next;
        list->tail->next = newnode;
    }
}

void add_last(list_t *list, int value)
{
    node_t *newnode = create_node(value);
    if(list->tail == NULL)
    {
        list->tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = list->tail->next;
        list->tail->next = newnode;
        list->tail = newnode;
    }
}

void del_first(list_t *list)
{
    if(list->tail == NULL)
    {
        return;
    }
    else
    {
        node_t *temp = list->tail->next;
        list->tail->next = temp->next;
        free(temp);
    }
}

void del_last(list_t *list)
{
    if(list->tail == NULL)
    {
        return;
    }
    else
    {
        node_t *temp = list->tail;
        node_t *trav = list->tail;
        while(trav->next != list->tail)
        {
            trav = trav->next;
        }
        trav->next = list->tail->next;
        list->tail = trav;
        free(temp);
    }
}

int main()
{
    list_t l;

    init_list(&l);

    add_first(&l, 40);
    add_first(&l, 30);
    add_first(&l, 20);
    add_first(&l, 10);
    add_last(&l, 50);

    //del_first(&l);
    del_last(&l);

    display_list(&l);

    printf("\n");

    return 0;
}