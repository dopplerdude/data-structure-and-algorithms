#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int find_max(int*, int, int);

int main()
{
    srand(time(0));

    int arr[20];
    int i;

    for(i = 0; i < 20; ++i)
    {
        arr[i] = rand()/100000;

        printf("arr[%d]:%d\n",i, arr[i]);
    }
    puts("");

    printf("\nMax element:%d\n", find_max(arr, 0, (sizeof(arr)/sizeof(arr[0])) - 1));
    return(0);
}

int find_max(int* pa, int start_index, int end_index)
{
    int mid_index, max_left, max_right;

    if(start_index == end_index)
        return(pa[start_index]);
    
    mid_index = (start_index + end_index) / 2;

    max_left = find_max(pa, start_index, mid_index);
    max_right = find_max(pa, mid_index + 1, end_index);

    if(max_left >= max_right)
    {
        return(max_left);
    }
    else
    {
        return(max_right);
    }
    
}