#include "monty.h"

/**
 * free_stack - frees a doubly linked stack
 * @stack: pointer to stack head
 */
void free_stack(stack_t **stack)
{
    stack_t *tmp;

    if (!stack || !(*stack))
        return;

    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}
