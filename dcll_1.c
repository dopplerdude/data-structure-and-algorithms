/* Doubly Circular Linked List */

#include <stdio.h>
#include <stdlib.h>

/* Symbolic constants */

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

typedef enum { FALSE = 0, TRUE = 1} bool;

/* typedefs */
typedef int data_t;
typedef int len_t;
typedef struct node node_t;
typedef node_t list_t;

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
static void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end);
static void generic_delete(node_t *p_delete_node);
static node_t* locate_node(list_t *p_list, data_t search_data);
static node_t* get_list_node(data_t new_data);

/* memory allocation routine */
static void* xmalloc(size_t size_in_bytes);


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
	cpa_assert(get_beg(p_list, &data) == LIST_EMPTY);
	cpa_assert(get_end(p_list, &data) == LIST_EMPTY);
	cpa_assert(pop_beg(p_list, &data) == LIST_EMPTY);
	cpa_assert(pop_end(p_list, &data) == LIST_EMPTY);
	cpa_assert(remove_beg(p_list) == LIST_EMPTY);
	cpa_assert(remove_end(p_list) == LIST_EMPTY);
	cpa_assert(remove_data(p_list, 0) == LIST_DATA_NOT_FOUND);
	cpa_assert(get_length(p_list) == 0);

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

	data = 0;
	s = get_beg(p_list, &data);
	cpa_assert(s == LIST_SUCCESS);
	printf("Beginning data: %d\n", data);
	
	data = 0;
	s = get_end(p_list, &data);
	cpa_assert(s == LIST_SUCCESS);
	printf("End data: %d\n", data);
	show_list(p_list, "\nAfter get_beg() and get_end():");
	
	data = 0;
	s = pop_beg(p_list, &data);
	cpa_assert(s == LIST_SUCCESS);
	printf("Popped beg data: %d\n", data);
	show_list(p_list, "\nAfter pop_beg():");
	
	data = 0;
	s = pop_end(p_list, &data);
	cpa_assert(s == LIST_SUCCESS);
	printf("popped end data: %d\n", data);
	show_list(p_list, "\nAfter pop_end():");
	
	s = remove_beg(p_list);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list, "\n After remove_beg():");
	
	s = remove_end(p_list);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list, "\n After remove_end():");
	
	s = remove_data(p_list, 0);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list, "\nAfter remove_data(0):");
	
	printf("get_length(p_list): %d\n", get_length(p_list));
	
	puts("\nTesting contains(p_list, 200)");
	if(contains(p_list, 200) == TRUE){
		puts("200 is in the list");
	}
	else
	{
		puts("200 is not in the list");
	}
	
	puts("\nTesting contains(p_list, 300)");
	if(contains(p_list, 300) == TRUE){
		puts("300 is in the list");
	}
	else
	{
		puts("300 is not in th list");
	}
	
	cpa_assert(insert_end(p_list, 100) == LIST_SUCCESS);
	show_list(p_list, "\n");
	printf("get_repeat_count(p_list, 4): %d\n", get_repeat_count(p_list, 4));
	printf("get_repeat_count(p_list, 200): %d\n", get_repeat_count(p_list, 200));
	printf("get_repeat_count(p_list, 100): %d\n", get_repeat_count(p_list, 100));
	
	s = destroy_list(&p_list);
	cpa_assert((s == LIST_SUCCESS) && (p_list == NULL));
	
	p_list1 = create_list();
	p_list2 = create_list();
	
	for(data = 5; data <= 95; data += 10)
	{
		insert_end(p_list1, data);
		insert_end(p_list2, data + 5);
	}
	
	show_list(p_list1, "\nList1:");
	show_list(p_list2, "\nList2:");
	
	p_concat_list = concat_lists(p_list1, p_list2);
	show_list(p_concat_list, "\nCOncatenated version of List1 and List2:");
	
	p_merge_list = merge_lists(p_list1, p_list2);
	show_list(p_merge_list, "\nMerged version of List1 and List2:");
	
	p_reversed_list = get_reversed_list(p_list1);
	show_list(p_reversed_list, "\nReversed version of List1:");
	
	show_list(p_list2, "\nList2 before undergoing reversal:");
	s = reverse_list(p_list2);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list2, "\nList2 after reversal:");

	s = append_list(p_list1, p_list2);
	cpa_assert(s == LIST_SUCCESS);
	show_list(p_list1, "\nList2 is appended to List1:");
	
	s = destroy_list(&p_list1);
	cpa_assert(s == LIST_SUCCESS && p_list1 == NULL);
	
	s = destroy_list(&p_concat_list);
	cpa_assert(s == LIST_SUCCESS && p_concat_list == NULL);
	
	s = destroy_list(&p_merge_list);
	cpa_assert(s == LIST_SUCCESS && p_merge_list == NULL);
	
	s = destroy_list(&p_reversed_list);
	cpa_assert(s == LIST_SUCCESS && p_reversed_list == NULL);
	
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
	p_list->data++;
	return (LIST_SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data)
{
	generic_insert(p_list->prev, get_list_node(new_data), p_list);
	p_list->data++;
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
	p_list->data++;
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
	p_list->data++;
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

status_t get_beg(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}
	*p_data = p_list->next->data;
	return (LIST_SUCCESS);
}

status_t get_end(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}
	*p_data = p_list->prev->data;
	
	return(LIST_SUCCESS);
}

status_t pop_beg(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}
	*p_data = p_list->next->data;
	
	generic_delete(p_list->next);
	p_list->data--;
	
	return (LIST_SUCCESS);
}

status_t pop_end(list_t *p_list, data_t *p_data)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}
	
	*p_data = p_list->prev->data;
	generic_delete(p_list->prev);
	p_list->data--;
	
	return (LIST_SUCCESS);
}

status_t remove_beg(list_t *p_list)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}
	generic_delete(p_list->next);
	p_list->data--;
	
	return (LIST_SUCCESS);
}

status_t remove_end(list_t *p_list)
{
	if(is_list_empty(p_list) == TRUE)
	{
		return (LIST_EMPTY);
	}
	generic_delete(p_list->prev);
	p_list->data--;
	
	return (LIST_SUCCESS);
}

status_t remove_data(list_t *p_list, data_t r_data)
{
	node_t *p_r_node = locate_node(p_list, r_data);
	
	if(p_r_node == NULL)
	{
		return (LIST_DATA_NOT_FOUND);
	}
	
	generic_delete(p_r_node);
	p_list->data--;
	
	return (LIST_SUCCESS);
}

len_t get_length(list_t *p_list)
{
	return (p_list->data);
}

bool contains(list_t *p_list, data_t search_data)
{
	return (locate_node(p_list, search_data) != NULL);
}

bool is_list_empty(list_t *p_list)
{
	return ((p_list == p_list->prev) && (p_list == p_list-> next));
}

node_t* get_location(list_t *p_list, data_t search_data)
{
	return (locate_node(p_list, search_data));
}

int get_repeat_count(list_t *p_list, data_t search_data)
{
	int count = 0;
	node_t *p_run = NULL;
	for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
	{
		if(p_run->data == search_data)
		{
			count++;
		}
	}
	return (count);
}

status_t destroy_list(list_t **pp_list)
{
	node_t *p_list = *pp_list;
	node_t *p_run = NULL, *p_run_next = NULL;
	
	for(p_run = p_list->next; p_run != p_list; p_run = p_run_next)
	{
		p_run_next = p_run->next;
		free(p_run);
	}

	free(p_list);
	*pp_list = NULL;
	
	return (LIST_SUCCESS);
}

list_t* concat_lists(list_t* p_list1, list_t* p_list2)
{
	list_t *p_new_list = create_list();
	node_t *p_run = NULL;
	
	for(p_run = p_list1->next; p_run != p_list1; p_run = p_run->next)
	{
		insert_end(p_new_list, p_run->data);
	}
	for(p_run = p_list2->next; p_run != p_list2; p_run = p_run->next)
	{
		insert_end(p_new_list, p_run->data);
	}
	return (p_new_list);
}

//status_t concat_lists(list_t *p_list1, list_t *p_list2, list_t **pp_concat_list);
list_t* merge_lists(list_t *p_list1, list_t *p_list2)
{
	list_t *p_new_list = create_list();
	node_t *p_run1, *p_run2;
	p_run1 = p_list1->next;
	p_run2 = p_list2->next;
	
	while(TRUE)
	{
		if(p_run1 == p_list1)
		{
			while(p_run2 != p_list2)
			{
				insert_end(p_new_list, p_run2->data);
				p_run2 = p_run2->next;
			}
			break;
		}
		
		if(p_run2 == p_list2)
		{
			while(p_run1 != p_list1)
			{
				insert_end(p_new_list, p_run1->data);
				p_run1 = p_run1->next;
			}
			break;
		}
		
		if(p_run1->data <= p_run2->data)
		{
			insert_end(p_new_list, p_run1->data);
			p_run1 = p_run1->next;
		}
		else
		{
			insert_end(p_new_list, p_run2->data);
			p_run2 = p_run2->next;
		}
	}
	return (p_new_list);
}

//status_t merge_lists(list_t *p_list1, list_t *p_list2, list_t **pp_merged_list);
list_t *get_reversed_list(list_t *p_list)
{
	list_t *p_reversed_list = create_list();
	node_t *p_run;
	
	for(p_run = p_list->next; p_run != p_list; p_run = p_run->next)
	{
		insert_beg(p_reversed_list, p_run->data);
	}
	return (p_reversed_list);
}

//status_t get_reversed_list(list *p_list, list_t **pp_reversed_list);
status_t reverse_list(list_t *p_list)
{
	node_t *p_run, *p_run_prev, *p_prev_orig;
	p_prev_orig = p_list->prev;
	for(p_run = p_list->prev->prev; p_run != p_list; p_run = p_run_prev)
	{
		p_run_prev = p_run->prev;
		generic_insert(p_list->prev, p_run, p_list);
	}
	p_list->next = p_prev_orig;
	p_prev_orig->prev = p_list;
	
	return (LIST_SUCCESS);
}

status_t append_list(list_t *p_list1, list_t *p_list2)
{
	p_list1->prev->next = p_list2->next;
	p_list2->next->prev = p_list1->prev;
	p_list1->prev = p_list2->prev;
	p_list2->prev->next = p_list1;
	free(p_list2);
	return (LIST_SUCCESS);
}

status_t list_to_array(list_t *p_list, data_t **pp_array, size_t *p_size)
{
	node_t *p_run;
	data_t *p_array = (data_t*)xmalloc(get_length(p_list) * sizeof(data_t));
	int index;
	for(p_run = p_list->next, index = 0; p_run != p_list; index++, p_run = p_run->next)
	{
		p_array[index] = p_run->data; 
	}
	*pp_array = p_array;
	*p_size = index;
	return (LIST_SUCCESS);
}

status_t array_to_list(data_t *p_array, size_t size, list_t **pp_list)
{
	list_t *p_list = create_list();
	int index;
	for(index = 0; index < size; index++)
	{
		insert_end(p_list, p_array[index]);
	}
	return (LIST_SUCCESS);
}

/* Auxillary routine implementation */
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
	p_mid->next = p_end;
	p_mid->prev = p_beg;
	p_beg->next = p_mid;
	p_end->prev = p_mid;
}

static void generic_delete(node_t* p_delete_node)
{
	p_delete_node->prev->next = p_delete_node->next;
	p_delete_node->next->prev = p_delete_node->prev;
	free(p_delete_node);
}

static node_t* locate_node(list_t* p_list, data_t search_data)
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

static node_t* get_list_node(data_t new_data)
{
	node_t* p_new_node = NULL;
	p_new_node = (node_t*) xmalloc(sizeof(node_t));
	p_new_node->data = new_data;
	p_new_node->next = NULL;
	p_new_node->prev = NULL;

	return (p_new_node);
}

/* memory allocation routine */
static void* xmalloc(size_t size_in_bytes)
{
	void* p_mem = NULL;
	p_mem = malloc(size_in_bytes);
	cpa_assert(p_mem != NULL);

	return (p_mem);
}




