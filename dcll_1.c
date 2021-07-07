/* Doubly Circular Linked List */

#include <stdio.h>
#include <stdlib.h>

/* Symbolic constants */
#define TRUE	1
#define FALSE	0
#define cpa_assert(COND)	do\
							{\
								if((COND) != TRUE)\
									{\
										fprintf(stderr, "Failed \""#COND"\" %s %d", __FILE__, __LINE__);\
										exit(EXIT_FAILURE);\
									}\
							}\
							while(0);\


/* Enumerations */
typedef enum {
	LIST_FAILURE = 0,
	LIST_SUCCESS,
	LIST_DATA_NOT_FOUND,
	LIST_EMPTY
}status_t;

/* typedefs */
typedef int data_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;
typedef int bool;

/* node layout definition */
struct node {
	data_t data;
	struct node* prev;
	struct node* next;
};

/* interface routines declarations */
list_t* create_list(void);

status_t insert_beg(list_t *p_list, data_t new_data);
status_t insert_end(list_t *p_list, data_t new_data);
status_t insert_after(list_t *p_list, data_t e_data, data_t new_data);
status_t insert_before(list_t *p_list, data_t e_data, data_t new_data);

status_t get_beg(list_t *p_list, data_t *p_data);
status_t get_end(list_t *p_list, data_t *p_data);
status_t pop_beg(list_t *p_list, data_t *p_data);
status_t pop_end(list_t *p_list, data_t *p_data);

status_t remove_beg(list_t *p_list);
status_t remove_end(list_t *p_list);
status_t remove_data(list_t *p_list, data_t r_data);

len_t get_length(list_t *p_list);
bool contains(list_t *p_list, data_t search_data);
bool is_list_empty(list_t *p_list);
node_t* get_location(list_t *p_list, data_t search_data);
int get_repeat_count(list_t *p_list, data_t search_data);
void show_list(list_t *p_list, const char *msg);

list_t* concat_lists(list_t* p_list1, list_t* p_list2);
//status_t concat_lists(list_t *p_list1, list_t *p_list2, list_t **pp_concat_list);
list_t* merge_lists(list_t *p_list1, list_t *p_list2);
//status_t merge_lists(list_t *p_list1, list_t *p_list2, list_t **pp_merged_list);
list_t *get_reversed_list(list_t *p_list);
//status_t get_reversed_list(list *p_list, list_t **pp_reversed_list);
status_t reverse_list(list_t *p_list);
status_t append_list(list_t *p_list1, list_t *p_list2);

status_t list_to_array(list_t *p_list, data_t **pp_array, size_t *p_size);
status_t array_to_list(data_t *p_array, size_t size, list_t **pp_list);

status_t destroy_list(list_t **pp_list);

/* list auxillary routine */
void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end);
void generic_delete(node_t *p_delete_node);
node_t* locate_node(list_t *p_list, data_t search_data);
node_t* get_list_node(data_t new_data);

/* memory allocation routine */
void* xmalloc(size_t size_in_bytes);


int main()
{
	status_t s;
	data_t data; 
	len_t len;
	list_t *p_list = NULL;
	list_t* p_list1 = NULL, * p_list2 = NULL;
	list_t* p_concat_list = NULL;
	list_t* p_merge_list = NULL;
	list_t* p_reversed_list = NULL;

	p_list = create_list();

	cpa_assert(p_list != NULL);
/*	cpa_assert(get_beg(p_list, &data) == LIST_EMPTY);
	cpa_assert(get_end(p_list, &data) == LIST_EMPTY);
	cpa_assert(pop_beg(p_list, &data) == LIST_EMPTY);
	cpa_assert(pop_end(p_list, &data) == LIST_EMPTY);
	cpa_assert(remove_beg(p_list) == LIST_EMPTY);
	cpa_assert(remove_end(p_list) == LIST_EMPTY);
	cpa_assert(remove_data(p_list, 0) == LIST_DATA_NOT_FOUND);
	cpa_assert(get_length(p_list) == 0);
*/
	show_list(p_list, "\nAfter create_list():");

	for (data = 0; data < 5; data++)
	{
		s = insert_beg(p_list, data);
		cpa_assert(s == LIST_SUCCESS);
	}
	show_list(p_list, "\nAfter insert_beg():");

	for (data = 5; data < 10; data++)
	{
		s = insert_end(p_list, data);
		cpa_assert(s == LIST_SUCCESS);
	}
	show_list(p_list, "\nAfter insert_end():");

	s = insert_after(p_list, 0, 100);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list, "\nAfter insert_after():");

	s = insert_before(p_list, 0, 200);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list, "\nAfter insert_before():");

	return (EXIT_SUCCESS);
}


/* Interface routine implementation */
list_t* create_list(void)
{
	node_t* p_new_node = get_list_node(0);
	p_new_node->data = 0;
	p_new_node->prev = p_new_node;
	p_new_node->next = p_new_node;
	return (p_new_node);
}

status_t insert_beg(list_t* p_list, data_t new_data)
{
	generic_insert(p_list, get_list_node(new_data), p_list->next);
	return (LIST_SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data)
{
	generic_insert(p_list->prev, get_list_node(new_data), p_list);
	return (LIST_SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* p_ref_node = locate_node(p_list, e_data);
	if (p_ref_node == NULL)
	{
		return (LIST_DATA_NOT_FOUND);
	}
	generic_insert(p_ref_node, get_list_node(new_data), p_ref_node->next);

	return (LIST_SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
	node_t* p_ref_node = locate_node(p_list, e_data);
	if (p_ref_node == NULL)
	{
		return (LIST_DATA_NOT_FOUND);
	}
	generic_insert(p_ref_node->prev, get_list_node(new_data), p_ref_node);
	return (LIST_SUCCESS);
}

void show_list(list_t *p_list, const char *msg)
{
	node_t* p_run;
	if (msg) {
		puts(msg);
	}
	printf("[BEG]<->");
	for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
	{
		printf("%d<->", p_run->data);
	}
	puts("[END]");
}
/* Auxillary routine implementation */
void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
	p_mid->next = p_end;
	p_mid->prev = p_beg;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

void generic_delete(node_t* p_delete_node)
{
	p_delete_node->prev->next = p_delete_node->next;
	p_delete_node->next->prev = p_delete_node->prev;
	free(p_delete_node);
}

node_t* locate_node(list_t* p_list, data_t search_data)
{
	node_t* p_run = NULL;
	for (p_run = p_list->next; p_run != p_list; p_run = p_run->next)
	{
		if (p_run->data == search_data)
		{
			return (p_run);
		}
	}
	return (NULL);
}

node_t* get_list_node(data_t new_data)
{
	node_t* p_new_node = NULL;
	p_new_node = (node_t*) xmalloc(sizeof(node_t));
	p_new_node->data = new_data;
	p_new_node->next = NULL;
	p_new_node->prev = NULL;

	return (p_new_node);
}

/* memory allocation routine */
void* xmalloc(size_t size_in_bytes)
{
	void* p_mem = NULL;
	p_mem = malloc(size_in_bytes);
	cpa_assert(p_mem != NULL);

	return (p_mem);
}




