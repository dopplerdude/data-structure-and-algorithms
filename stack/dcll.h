/*  Headers */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*** SYMBOLIC CONSTANTS ***/
#define TRUE 1
#define FALSE 0
#define NO_DATA_FOUND 2
#define success 1
#define LIST_EMPTY 3

/*** TYPEDEFS ***/
typedef int status_t;
typedef int data_t;
typedef int bool;

typedef struct node{
    data_t data;
    struct node *next;
    struct node *prev;
} node_t;

typedef node_t list_t;

/*** INTERFACE ***/
list_t* create_list(void);
status_t insert_beg(list_t*, data_t);
status_t insert_end(list_t*, data_t);
void show_list(list_t*, char*);
void destroy_list(list_t**);
status_t remove_beg(list_t*);
status_t remove_end(list_t*);
bool is_list_empty(list_t*);
void reverse_list(list_t* p_list);
status_t get_beg(list_t*, data_t*);
status_t get_end(list_t*, data_t*);
status_t pop_beg(list_t*, data_t*);
status_t pop_end(list_t*, data_t*);

/*** AUXILIARY FUNCTIONS ***/
node_t* get_list_node(data_t data);
void* xmalloc(size_t size);
status_t generic_insert(list_t* p_beg, list_t* p_mid, list_t* p_end);
status_t generic_delete(list_t*);
