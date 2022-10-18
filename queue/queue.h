#include <stdint.h>
#include <stddef.h>

typedef struct queue
{
	int32_t head;
	int32_t tail;
	int32_t capacity;
	int32_t size;
	void** p_data;
}queue_t;

typedef queue_t* queue_handle_t;

typedef enum queue_status
{
	FAILURE = 0,
	SUCCESS,
	QUEUE_FULL,
	QUEUE_EMPTY	
}status_t;

typedef enum boolean_type
{
	FALSE = 0,
	TRUE
}BOOL;

#define assert( x ) 	if(( x ) == FALSE) {for( ;; );}


queue_handle_t create_queue(int32_t max_queue_len);
status_t queue_push(queue_handle_t queue_handle, void* p_data, size_t size_in_bytes);
void* get_data(void* p_data, size_t size_in_bytes);
status_t queue_pop(queue_handle_t queue_handle, void* p_data, size_t size_in_bytes);
BOOL queue_empty(queue_handle_t queue_handle);
BOOL queue_full(queue_handle_t queue_handle);
status_t queue_delete(queue_handle_t* p_queue_handle);
void queue_show(queue_handle_t queue_handle);

