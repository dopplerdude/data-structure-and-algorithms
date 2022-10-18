#include <stdlib.h>
#include "queue.h"
#include <string.h>

queue_handle_t create_queue(int32_t max_queue_len)
{
	queue_handle_t queue_handle = (queue_handle_t)malloc(sizeof(queue_handle_t));
	assert(queue_handle != NULL);
	
	queue_handle->capacity = max_queue_len + 1;
	queue_handle->size = 0;
	queue_handle->head = queue_handle->capacity;
	queue_handle->tail = 0;
	queue_handle->p_data = (void**)malloc(sizeof(void*) * queue_handle->capacity);
	assert(queue_handle->p_data != NULL);
	memset(queue_handle->p_data, 0, sizeof(void*) * queue_handle->capacity);
	return(queue_handle);
}

status_t queue_delete(queue_handle_t* p_queue_handle)
{
	queue_handle_t queue_handle = *p_queue_handle;
	if(queue_handle != NULL);
	{
		if(queue_handle->p_data != NULL)
		{
			for(int32_t i = 0; i < queue_handle->capacity; ++i)
			{
				if(queue_handle->p_data[i] != NULL)
				{
					free(queue_handle->p_data[i]);
					queue_handle->p_data[i] = NULL;
				}
			}

			free(queue_handle->p_data);
			queue_handle->p_data = NULL;
		}
		free(queue_handle);
		queue_handle = NULL;
	}
	return(SUCCESS);
}

status_t queue_push(queue_handle_t queue_handle, void* p_data, size_t size_in_bytes)
{
	if(queue_full(queue_handle))
	{
		return(QUEUE_FULL);
	}
	queue_handle->p_data[queue_handle->tail++] = get_data(p_data, size_in_bytes);
	queue_handle->tail = queue_handle->tail % queue_handle->capacity;
	queue_handle->size++;
	return(SUCCESS); 
}

void* get_data(void* p_data, size_t size_in_bytes)
{
	void* data = malloc(size_in_bytes);
	assert(data != NULL);
	strncpy(data, p_data, size_in_bytes);
	return(data);
}

status_t queue_pop(queue_handle_t queue_handle, void* p_data, size_t size_in_bytes)
{
	if(queue_empty(queue_handle) == TRUE)
	{
		return(QUEUE_EMPTY);
	}	
	assert(p_data != NULL);

	queue_handle->head = queue_handle->head % queue_handle->capacity;
	strncpy(p_data, queue_handle->p_data[queue_handle->head++], size_in_bytes);
	return(SUCCESS);
}

BOOL queue_empty(queue_handle_t queue_handle)
{
	return((queue_handle->head % queue_handle->capacity) == queue_handle->tail);
}

BOOL queue_full(queue_handle_t queue_handle)
{
	return(queue_handle->tail+1 == queue_handle->head);
}

//void queue_show(queue_handle_t queue_handle);
