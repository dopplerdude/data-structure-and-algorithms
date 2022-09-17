#include "stack.h"

stack_t* create_stack(void)
{
    return(create_list());
}

status_t push(stack_t* p_stack, data_t data)
{
    return(insert_end(p_stack, data));
}

status_t pop(stack_t* p_stack, data_t* p_data)
{
    return(pop_end(p_stack, p_data));
}

status_t top(stack_t* p_stack, data_t* p_data)
{
    return(get_end(p_stack, p_data));
}

bool is_stack_empty(stack_t* p_stack)
{
    return(is_list_empty(p_stack));
}

void show_stack(stack_t* p_stack, char* msg)
{
    show_list(p_stack, msg);
}

void destroy_stack(stack_t** pp_stack)
{
    destroy_list(pp_stack);
}
