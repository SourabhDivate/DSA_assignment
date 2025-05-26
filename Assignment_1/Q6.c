#include<stdio.h>

int main()
{
    int arr[] = {10,20,15,3,4,4,1};
    int num, i, count = 0;

    printf("Enter number to find rank : ");
    scanf("%d",&num);

    for(i=0 ; i<(sizeof(arr)/4) ; i++)
    {
        if(arr[i] <= num)
        {
            count++;
        }
    }

    printf("Rank of given number is %d\n",count);

    return 0;
}