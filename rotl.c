#include "monty.h"

/**
 * rotl - rotates stack to the left
 * @stack: stack head
 * @line_number: unused
 */
void rotl(stack_t **stack, unsigned int line_number)
{
    stack_t *first;
    stack_t *last;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    first = *stack;
    last = *stack;

    /* move to last node */
    while (last->next)
        last = last->next;

    /* new head is second node */
    *stack = first->next;
    (*stack)->prev = NULL;

    /* attach old head at end */
    last->next = first;
    first->prev = last;
    first->next = NULL;
}
