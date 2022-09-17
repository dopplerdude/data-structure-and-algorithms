#include "stack.h"
#include <string.h>
#include "itoa.h"

int main(void)
{
    int data;
    char buffer[10];

    stack_t* p_stack = create_stack();
    assert(p_stack);

    push(p_stack, 10);
    push(p_stack, 20);
    push(p_stack, 30);
    push(p_stack, 40);

    show_stack(p_stack, "******** STACK **********");
    printf("Performing POP: %s\n", pop(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");
    show_stack(p_stack, "******** STACK **********");
    
    printf("Performing TOP: %s\n", top(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");

    printf("Performing pop: %s\n", pop(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");
    show_stack(p_stack, "******** STACK **********");

    push(p_stack, 50);
    show_stack(p_stack, "******** STACK **********");

    printf("Performing pop: %s\n", pop(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");
    show_stack(p_stack, "******** STACK **********");

    printf("Performing pop: %s\n", pop(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");
    show_stack(p_stack, "******** STACK **********");

    printf("Performing pop: %s\n", pop(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");
    show_stack(p_stack, "******** STACK **********");

    printf("Performing pop: %s\n", pop(p_stack, &data) != STACK_EMPTY? itoa(data, buffer, 10):"STACK IS EMPTY!!");
    show_stack(p_stack, "******** STACK **********");

    destroy_stack(&p_stack);

    return(0);
}