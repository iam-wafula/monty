#include "monty.h"

/**
 * pstr - prints a string from stack
 * @stack: stack head
 * @line_number: unused
 */
void pstr(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
    int value;

    (void)line_number;

    if (!stack || !*stack)
    {
        printf("\n");
        return;
    }

    temp = *stack;

    while (temp)
    {
        value = temp->n;

        if (value <= 0 || value > 127)
            break;

        printf("%c", value);

        temp = temp->next;
    }

    printf("\n");
}
