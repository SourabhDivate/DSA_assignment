#include<stdio.h>

int last;

int linear_search(int arr[], int size, int key)
{
    int index, i;
    for(i=0 ; i<size ; i++)
    {
        if(key == arr[i])
        {
            index = i;
        }
        last = index;
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,2,1,5,7,8};
    int index, key, size = 10;

    printf("Enter key :");
    scanf("%d",&key);

    linear_search(arr, size, key);

    printf("key found at index %d\n",last);

    return 0;
}