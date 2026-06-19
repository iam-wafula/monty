#include "monty.h"

/**
 * mul - multiplies top two elements of stack
 * @stack: pointer to stack
 * @line_number: line number in file
 */
void mul(stack_t **stack, unsigned int line_number)
{
    int result;
    stack_t *temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    result = (*stack)->next->n * (*stack)->n;

    (*stack)->next->n = result;

    temp = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;

    free(temp);
}
