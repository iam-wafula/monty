#include "monty.h"

/**
 * rotr - rotates stack to the right
 * @stack: stack head
 * @line_number: unused
 */
void rotr(stack_t **stack, unsigned int line_number)
{
    stack_t *last;

    (void)line_number;

    if (!stack || !*stack || !(*stack)->next)
        return;

    last = *stack;

    /* move to last node */
    while (last->next)
        last = last->next;

    /* detach last node */
    if (last->prev)
        last->prev->next = NULL;

    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;

    *stack = last;
}
