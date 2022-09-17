#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int binary_search(int*, int, int, int);
void insertion_sort(int*, ssize_t);

int main()
{
    srand(time(0));
    int arr[10];
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); ++i)
    {
        arr[i] = rand()%100000;
    }
    insertion_sort(arr, (sizeof(arr)/sizeof(arr[0])));

    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); ++i)
    {
        printf("arr[%d]:%d\n", i, arr[i]);
    }

    printf("Search 478: found at index:%d\n", binary_search(arr, 0, (sizeof(arr)/sizeof(arr[0])) - 1, arr[3]));

    return(0);
}

void insertion_sort(int* pa, ssize_t size)
{
    int i, j, key;
    for(j = 1; j < size; ++j)
    {
        key = pa[j];
        i = j - 1;

        while((i > -1) && pa[i] > key)
        {
            pa[i+1] = pa[i];
            i -= 1;
        }
        pa[i+1] = key;
    }
}

int binary_search(int* pa, int start_index, int end_index, int n)
{
    int mid_index;

    if(start_index <= end_index)
    {
        mid_index = (start_index + end_index)/2;
        if(n == pa[mid_index])
        {
            return(mid_index);
        }
        else if(n < pa[mid_index])
        {
            return(binary_search(pa, start_index, mid_index - 1, n));
        }
        else if(n > pa[mid_index])
        {
            return(binary_search(pa, mid_index+1, end_index, n));
        }
    }

    return(-1); 

}
