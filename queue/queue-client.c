#include "queue.h"
#include <stdio.h>

int main()
{
    status_t status;
    int temp;
    queue_handle_t q = create_queue(5);
    if (q) printf("Queue successfully created\n");

    int data[6] = {10, 90, 30, 60, 70, 20};
    for(int i = 0; i < 6; ++i)
    {
        status = queue_push(q, &data[i], sizeof(int)); 
        if ( status != SUCCESS)
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
        status = queue_pop(q, &temp, sizeof(int)); 
        if ( status != SUCCESS)
        {
            printf("Queue Pop error:%d\n", status);
        } 
        else
        {
            printf("Queue Pop : %d\n", temp);
        }
    }

    queue_delete(&q);

    return(0);
}
