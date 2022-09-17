#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0
#define NO_DATA_FOUND 2
#define success 1
#define LIST_EMPTY 3

typedef int status_t;
typedef int data_t;
typedef int bool;

typedef struct node{
data_t data;
struct node *next;
struct node *prev;
} node_t;

typedef node_t list_t;

list_t* create_list(void);
status_t insert_beg(list_t*, data_t);
void show_list(list_t*, char*);
void destroy_list(list_t**);
status_t remove_beg(list_t*);
status_t remove_end(list_t*);
bool is_list_empty(list_t*);
void reverse_list(list_t* p_list);

node_t* get_list_node(data_t data);
void* xmalloc(size_t size);
status_t generic_insert(list_t* p_beg, list_t* p_mid, list_t* p_end);
status_t generic_delete(list_t*);

int main(void)
{
    list_t *list = create_list();

    insert_beg(list, 10);
    insert_beg(list, 20);
    insert_beg(list, 30);

    show_list(list, "============= LINKED LIST =================");

    remove_beg(list);
    show_list(list, "============= LINKED LIST =================");

    remove_end(list);
    show_list(list, "============= LINKED LIST =================");

    insert_beg(list,15);
    show_list(list, "============= LINKED LIST =================");

    insert_beg(list,65);
    show_list(list, "============= LINKED LIST =================");
    
    insert_beg(list,85);
    show_list(list, "============= LINKED LIST =================");
    
    insert_beg(list,75);
    show_list(list, "============= LINKED LIST =================");

    reverse_list(list);
    show_list(list, "============= LINKED LIST =================");

    destroy_list(&list);

    return(0);
}

list_t* create_list()
{
    node_t* p_node = get_list_node(0);
    p_node->next = p_node;
    p_node->prev = p_node;
    return(p_node);
}

status_t insert_beg(list_t *p_list, data_t data)
{
    return(generic_insert(p_list, get_list_node(data), p_list->next));
}

status_t remove_beg(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);
    
    generic_delete(p_list->next);
    return(success);
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return(LIST_EMPTY);
    
    generic_delete(p_list->prev);
    return(success);
}

void show_list(list_t* p_list, char* msg)
{
    list_t* p_run;
    if(msg)
        puts(msg);
    printf("<BEG>");

    for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
        printf("<%d>", p_run->data);

    puts("<END>");
}

void reverse_list(list_t* p_list)
{
    node_t *p_run, *p_run_prev, *p_prev_orig;
    p_prev_orig = p_list->prev;

    for(p_run = p_list->prev->prev; p_run != p_list; p_run = p_run_prev)
    {
        p_run_prev = p_run->prev;
        generic_insert(p_list->prev, p_run, p_list);
    }
    p_prev_orig->prev = p_list;
    p_list->next = p_prev_orig;
}

void destroy_list(list_t **pp_list)
{
    list_t* p_list = *pp_list;
    node_t* p_run, *p_run_next;

    for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
    {
        p_run_next = p_run->next;
        free(p_run);
    }
    free(p_list);
    *pp_list = NULL;

}

status_t generic_insert(list_t* p_beg, list_t* p_mid, list_t* p_end)
{
    p_mid->next = p_beg->next;
    p_mid->prev = p_end->prev;
    p_beg->next = p_mid;
    p_end->prev = p_mid; 

    return(TRUE);
}

status_t generic_delete(list_t* p_delete)
{
    p_delete->next->prev = p_delete->prev;
    p_delete->prev->next = p_delete->next;
    free(p_delete);
    p_delete = NULL;
    return(success);
}

node_t* get_list_node(data_t data)
{
    node_t* p_new_node = (node_t*)xmalloc(sizeof(node_t));
    p_new_node->data = data;
    return(p_new_node);
}

status_t is_list_empty(list_t* p_list)
{
    return((p_list->next == p_list) && (p_list->prev == p_list));
}
void* xmalloc(size_t size)
{
    void* p = malloc(size);
    assert(p != NULL);
    return(p);
}