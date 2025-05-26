#include<stdio.h>

int linear_search(int arr[], int size, int key, int count)
{
    int index, i, occur;
    for(i=0 ; i<size ; i++)
    {
        if(key == arr[i])
        {
            index = i;
            occur++;
            if(count == occur)
            {
                return index;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,2,1,5,7,8};
    int index, key, size = 10,count = 0;

    printf("Enter key :");
    scanf("%d",&key);
    printf("Enter ocurrance no :");
    scanf("%d",&count);

    index = linear_search(arr, size, key, count);

    printf("key found at index %d\n",index);

    return 0;
}