#include "my-queue.h"
#include <stdio.h>

int main()
{
    status_t status;
    int temp;
    my_queue_handle_t q = create_my_queue(5);
    if (q) printf("Queue successfully created\n");

    int data[6] = {10, 90, 30, 60, 70, 20};
    for(int i = 0; i < 6; ++i)
    {
        status = my_queue_push(q, &data[i], sizeof(int)); 
        if ( status != QUEUE_SUCCESS)
        {
            printf("Queue Push error:%d\n", status);
        } 
        else
        {
            printf("Queue Push :%d\n", data[i]);
        }
        
    }

    for(int i = 0; i < 6; ++i)
    {
        status = my_queue_pop(q, &temp, sizeof(int)); 
        if ( status != QUEUE_SUCCESS)
        {
            printf("Queue Pop error:%d\n", status);
        } 
        else
        {
            printf("Queue Pop : %d\n", temp);
        }
    }

    my_queue_delete(&q);

    return(0);
}
