#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


#define TRUE    1
#define FALSE   0
#define SUCCESS 1
#define BST_NO_MEM  2

typedef int data_t;
typedef int status_t;
typedef int bool;

typedef struct bst_node{
    data_t data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
}bst_node_t;

typedef struct bst{
    bst_node_t* p_root_node;
    data_t nr_elements;
}bst_t;

bst_t* create_bst(void);
bst_node_t* get_bst_node(data_t);
status_t insert(bst_t*, data_t);
bool is_empty_bst(bst_t*);
bool search_bst(bst_t*, data_t);
void show_bst(bst_t*, char*);
void destroy_bst(bst_t*);

int main()
{
    bst_t* p_bst = create_bst();

    insert(p_bst, 100);
    insert(p_bst, 30); 
    insert(p_bst, 10);
    insert(p_bst, 20);
    insert(p_bst, 500);
    insert(p_bst, 600);
    printf("Number of nodes in BST : %d\n", p_bst->nr_elements);
    printf("Searching BST for 500 : %s\n", search_bst(p_bst, 500) == TRUE? "FOUND":"NOT FOUND");
    printf("Searching BST for 300 : %s\n", search_bst(p_bst, 300) == TRUE? "FOUND":"NOT FOUND");
    printf("Searching BST for 20 : %s\n", search_bst(p_bst, 20) == TRUE? "FOUND":"NOT FOUND");
    return(0);
}

bst_t* create_bst(void)
{
    bst_t* p_bst = (bst_t*)malloc(sizeof(bst_t));
    assert(p_bst);

    p_bst->nr_elements = 0;
    p_bst->p_root_node = NULL;
    return(p_bst);
}

bst_node_t* get_bst_node(data_t data)
{
    bst_node_t* p_new_bst_node = (bst_node_t*)malloc(sizeof(bst_node_t));
    assert(p_new_bst_node);
    p_new_bst_node->data = data;
    p_new_bst_node->left = NULL;
    p_new_bst_node->right = NULL;
    p_new_bst_node->parent = NULL;
    return(p_new_bst_node);
}

status_t insert(bst_t* p_bst, data_t data)
{
    bst_node_t* p_new_bst_node = get_bst_node(data);
    bst_node_t* p_run = NULL;

    if(is_empty_bst(p_bst) == TRUE)
    {
        p_bst->p_root_node = p_new_bst_node;
    }
    else
    {
        p_run = p_bst->p_root_node;
        while(TRUE)
        {
            if(data <= p_run->data)
            {
                if(p_run->left == NULL)
                {
                    p_run->left = p_new_bst_node;
                    p_run->left->parent = p_run;
                    break;   
                }
                else
                {
                    p_run = p_run->left;
                    continue;
                }                
            }
            else
            {
                if(p_run->right == NULL)
                {
                    p_run->right = p_new_bst_node;
                    p_run->right->parent = p_run;
                    break;
                }
                else
                {
                    p_run = p_run->right;
                    continue;
                }                
            }
            
        };
    }
    p_bst->nr_elements += 1;
    return(SUCCESS);    
}

bool is_empty_bst(bst_t* p_bst)
{
    return(p_bst->p_root_node == NULL);
}

bool search_bst(bst_t* p_bst, data_t data)
{
    bst_node_t* p_run = NULL;
    if(is_empty_bst(p_bst) == TRUE)
        return(FALSE);

    p_run = p_bst->p_root_node;

    while(p_run != NULL)
    {
        if(data == p_run->data)
        {
            return(TRUE);
        }
        else if(data <= p_run->data)
        {
            p_run = p_run->left;
        }
        else
        {
            p_run = p_run->right;
        }        
    }
    return(FALSE);
}

void show_bst(bst_t*, char*);
void destroy_bst(bst_t*);
