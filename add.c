#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number in file
 */
void add(stack_t **stack, unsigned int line_number)
{
    int sum;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    sum = (*stack)->n + (*stack)->next->n;

    (*stack)->next->n = sum;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    free(temp);
}
