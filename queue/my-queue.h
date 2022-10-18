#include <stdint.h>
#include <stddef.h>

typedef struct my_queue
{
	int32_t head;
	int32_t tail;
	int32_t capacity;
	int32_t size;
	void** p_data;
}my_queue_t;

typedef my_queue_t* my_queue_handle_t;

typedef enum my_queue_status
{
	QUEUE_FAILURE = 0,
	QUEUE_SUCCESS,
	QUEUE_FULL,
	QUEUE_EMPTY
}status_t;

typedef enum boolean_type
{
	FALSE = 0,
	TRUE
}BOOL;

#ifdef assert
#undef assert
#define assert( x ) 	if(( x ) == FALSE) {for( ;; );}
#endif

my_queue_handle_t create_my_queue(int32_t max_my_queue_len);
status_t my_queue_push(my_queue_handle_t my_queue_handle, void* p_data, size_t size_in_bytes);
void* get_data(void* p_data, size_t size_in_bytes);
status_t my_queue_pop(my_queue_handle_t my_queue_handle, void* p_data, size_t size_in_bytes);
BOOL my_queue_empty(my_queue_handle_t my_queue_handle);
BOOL my_queue_full(my_queue_handle_t my_queue_handle);
status_t my_queue_delete(my_queue_handle_t* p_my_queue_handle);
void my_queue_show(my_queue_handle_t my_queue_handle);

