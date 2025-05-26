#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,-1,2,1,0,4,-1,7,8};
    int flag;
    for(int i=0 ; i<sizeof(arr)/4 ; i++)
    {
        flag = 0;
        for(int j=i+1 ; j<sizeof(arr)/4 ; j++)
        {
            if(arr[i] == arr[j])
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("1st non repeated value %d.\n",arr[i]);
            return 0;
        }
    }

}