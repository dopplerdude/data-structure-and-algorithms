/*** HEADERS ***/
#include "dcll.h"

/*** SYMBOLIC CONSTANTS ***/
#define STACK_EMPTY LIST_EMPTY

/*** TYPEDEFS ***/
typedef list_t stack_t;

/*** INTERFACE FUNCTIONS ***/
stack_t* create_stack(void);
status_t push(stack_t*, data_t);
status_t pop(stack_t*, data_t*);
status_t top(stack_t*, data_t*);
bool is_stack_empty(stack_t*);
void show_stack(stack_t*, char*);
void destroy_stack(stack_t**);

/*** AUXILIARY FUNCTIONS ***/

