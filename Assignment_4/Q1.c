#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

typedef struct list{
    node_t *head;
}list_t;

void init_list(list_t *list)
{
    list->head = NULL;
}

int isEmpty(list_t *list)
{
    return list->head == NULL;
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
    newnode->next = list->head;
    list->head = newnode;
}

void display_list(list_t *list)
{
    node_t *trav = list->head;
    printf("List : ");
    while(trav != NULL)
    {
        printf("%-4d",trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void delete_list(list_t *list)
{
    node_t *trav = list->head;
    while(trav != NULL)
    {
        node_t *temp = trav;
        trav = trav->next;
        free(temp);
    }
    list->head = NULL;
}

void add_last(list_t *list, int value)
{
    node_t *newnode = create_node(value);
    if(list->head == NULL)
    {
        list->head = newnode;
    }
    else
    {
        node_t *trav = list->head;
        while(trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = newnode;
    }
}

void delete_first(list_t *list)
{
    if(list->head == NULL)
    {
        return;
    }
    else
    {
        node_t *temp = list->head;
        list->head = list->head->next;
        free(temp);
    }
}

void delete_last(list_t *list)
{
    if(list->head == NULL)
    {
        return;
    }
    else
    {
        node_t *trav = list->head;
        while(trav->next->next != NULL)
        {
            trav = trav->next;
        }
        node_t *temp = trav->next;
        trav->next = NULL;
        free(temp);
    }
}

void add_position(list_t *list, int value, int pos)
{
    node_t *newnode = create_node(value);
    if(list->head == NULL)
    {
        list->head = newnode;
    }
    else if(pos == 1)
    {
        add_first(list, value);
        free(newnode);
    }
    else if(pos < 1)
    {
        return;
    }
    else
    {
        node_t *trav = list->head;
        for(int i=1 ; i<pos-1 && trav->next != NULL ; i++)
        {
            trav = trav->next;
        }
        newnode->next = trav->next;
        trav->next = newnode;
    }
}

void del_position(list_t *list, int pos)
{
    if(list->head == NULL)
    {
        return;
    }
    else if(pos == 1)
    {
        delete_first(list);
    }
    else
    {
        node_t *trav = list->head;
        for(int i = 1 ; i < pos-1 && trav->next != NULL; i++)
        {
            trav = trav->next;
        }
        node_t *temp = trav->next;
        if(temp == NULL)
        {
            return;
        }
        trav->next = trav->next->next;
        free(temp);
    }
}

void inser_after(list_t *list, int value, int pos)
{
    node_t *newnode = create_node(value);
    if(list->head == NULL)
    {
        list->head = newnode;
    }
    else if(pos == 1)
    {
        //node_t *newnode = create_node(value);
        newnode->next = list->head->next;
        list->head->next = newnode;
    }
    else if(pos == 0)
    {
        newnode->next = list->head;
        list->head = newnode;
    }
    else if(pos < 1)
    {
        return;
    }
    else
    {
        node_t *trav = list->head;
        for(int i=1 ; i<pos && trav->next != NULL ; i++)
        {
            trav = trav->next;
        }
        newnode->next = trav->next;
        trav->next = newnode;
    }
}

void insert_before(list_t *list, int value, int pos)
{
    node_t *newnode = create_node(value);
    if(list->head == NULL)
    {
        list->head = newnode;
    }
    else if(pos == 2)
    {
        newnode->next = list->head;
        list->head = newnode;
    }
    else if(pos <= 1)
    {
        return;
    }
    else
    {
        node_t *trav = list->head;
        for(int i=1 ; i<pos-2 && trav->next != NULL ; i++)
        {
            trav = trav->next;
        }
        newnode->next = trav->next;
        trav->next = newnode;
    }
}

int main()
{
    list_t l1;

    init_list(&l1);

    add_first(&l1, 40);
    add_first(&l1, 30);
    add_first(&l1, 20);
    add_first(&l1, 10);
    add_last(&l1, 50);
    //delete_first(&l1);
    //delete_last(&l1);
    //add_position(&l1, 100, 2);
    //del_position(&l1, 8);
    //inser_after(&l1, 100, 0);
    insert_before(&l1, 100, 8);

    display_list(&l1);

    delete_list(&l1);

    return 0;
}
