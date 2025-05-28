#include<stdio.h>

#define SIZE    6

void print_array(int arr[], int N)
{
    //printf("Before...\n");
    for(int i = 0; i<N ; i++)
    {
        printf("%4d",arr[i]);
    }
    printf("\n");
}

void insertion_sort(int arr[], int size)
{
    for(int i=1 ; i < size ; i++)
    {
        int temp = arr[i];
        int j;
        for(j = i-1 ; j >= 0 ; j--)
        {
            if(arr[j] < temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main()
{
    int arr[] = {55,22,33,11,44,66};

    printf("Before...\n");
    print_array(arr, SIZE);

    insertion_sort(arr, SIZE);

    printf("After...\n");
    print_array(arr, SIZE);



    return 0;
}