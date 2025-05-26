#include<stdio.h>

int binary_search(int arr[], int size, int key)
{
    int left = 0, right = size - 1, mid, i;

    while(left <= right)
    {
        mid = (right + left) / 2;
        if(key == arr[mid])
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    return -1;
}

int main()
{
    int arr[9] = {99,88,77,66,55,44,33,22,11};
    int key, index, size = 9;

    printf("Enter key : ");
    scanf("%d",&key);

    index = binary_search(arr, 9, key);
    if(index < 0)
    {
        printf("Key not found.\n");
    }
    else    
        printf("Key found at index %d.\n",index);

    return 0;
}