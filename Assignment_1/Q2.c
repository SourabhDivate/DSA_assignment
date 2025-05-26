#include<stdio.h>
#include<string.h>

typedef struct employee{
    int empid;
    char name[20];
}employee_t; 

int linear_search1(employee_t emp[], int empid)
{
    int i;
    for(i=0 ; i<5 ; i++)
    {
        if(empid == emp[i].empid)
        {
            return i;
        }
    }
}

int linear_search2(employee_t emp[], char name[20])
{
    int i;
    for(i=0 ; i<5 ; i++)
    {
        if(strcmp(name, emp[i].name) == 0)
        {
            return 1;
        }
    }
}


int main()
{
    int key, index, choice, empid;
    char name[20];
    employee_t emp[5] = {
        {
            .empid = 1,
            .name = "sourabh"
        },
        {
            .empid = 2,
            .name = "pratik"
        },
        {
            .empid = 3,
            .name = "varad"
        },
        {
            .empid = 4,
            .name = "satyam"
        },
        {
            .empid = 5,
            .name = "saurabh"
        }
    };

    printf("1. search by empid\n2. search by name\nEnter choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            printf("Enter empid : ");
            scanf("%d",&empid);
            index = linear_search1(emp, empid);
            printf("Employee found at index %d\n",index);
            break;
        case 2:
            printf("Enter name : ");
            scanf("%s",name);
            index = linear_search2(emp, name);
            if(index == 1)
            printf("Employee found.\n");
            break;
        default:
            printf("invalid choice.\n");
    }

    return 0;
}