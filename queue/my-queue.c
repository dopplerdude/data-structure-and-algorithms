#include <stdlib.h>
#include "my-queue.h"
#include <string.h>

my_queue_handle_t create_my_queue(int32_t max_my_queue_len)
{
	my_queue_handle_t my_queue_handle = (my_queue_handle_t)malloc(sizeof(my_queue_t));
	assert(my_queue_handle != NULL);
	void** p_data = NULL;
	my_queue_handle->capacity = max_my_queue_len + 1;
	my_queue_handle->size = 0;
	my_queue_handle->head = my_queue_handle->capacity;
	my_queue_handle->tail = 0;
	p_data = (void**)malloc(sizeof(void*) * my_queue_handle->capacity);
	my_queue_handle->p_data = p_data;
	assert(my_queue_handle->p_data != NULL);
	memset(my_queue_handle->p_data, 0, sizeof(void*) * my_queue_handle->capacity);
	return(my_queue_handle);
}

status_t my_queue_delete(my_queue_handle_t* p_my_queue_handle)
{
	my_queue_handle_t my_queue_handle = *p_my_queue_handle;
	if(my_queue_handle != NULL)
	{
		if(my_queue_handle->p_data != NULL)
		{
			for(int32_t i = 0; i < my_queue_handle->capacity; ++i)
			{
				if(my_queue_handle->p_data[i] != NULL)
				{
					free(my_queue_handle->p_data[i]);
					my_queue_handle->p_data[i] = NULL;
				}
			}

			free(my_queue_handle->p_data);
			my_queue_handle->p_data = NULL;
		}
		free(my_queue_handle);
		my_queue_handle = NULL;
	}
	return(QUEUE_SUCCESS);
}

status_t my_queue_push(my_queue_handle_t my_queue_handle, void* p_data, size_t size_in_bytes)
{
	if(my_queue_full(my_queue_handle))
	{
		return(QUEUE_FULL);
	}
	my_queue_handle->p_data[my_queue_handle->tail++] = get_data(p_data, size_in_bytes);
	my_queue_handle->tail = my_queue_handle->tail % my_queue_handle->capacity;
	my_queue_handle->size++;
	return(QUEUE_SUCCESS);
}

void* get_data(void* p_data, size_t size_in_bytes)
{
	void* data = malloc(size_in_bytes);
	assert(data != NULL);
	strncpy(data, p_data, size_in_bytes);
	return(data);
}

status_t my_queue_pop(my_queue_handle_t my_queue_handle, void* p_data, size_t size_in_bytes)
{
	if(my_queue_empty(my_queue_handle) == TRUE)
	{
		return(QUEUE_EMPTY);
	}	
	assert(p_data != NULL);

	my_queue_handle->head = my_queue_handle->head % my_queue_handle->capacity;
	strncpy(p_data, my_queue_handle->p_data[my_queue_handle->head++], size_in_bytes);
	my_queue_handle->size--;
	return(QUEUE_SUCCESS);
}

BOOL my_queue_empty(my_queue_handle_t my_queue_handle)
{
	return((my_queue_handle->head % my_queue_handle->capacity) == my_queue_handle->tail);
}

BOOL my_queue_full(my_queue_handle_t my_queue_handle)
{
	return(my_queue_handle->tail+1 == my_queue_handle->head);
}

//void my_queue_show(my_queue_handle_t my_queue_handle);
