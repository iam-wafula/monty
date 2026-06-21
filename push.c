#include "monty.h"

extern int mode;

/**
 * push - adds node depending on mode
 */
void push(stack_t **stack, unsigned int line_number)
{
    stack_t *new, *temp;
    char *arg;
    int i, n;

    arg = strtok(NULL, " \t\n");

    if (!arg)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    i = 0;
    if (arg[0] == '-')
        i = 1;

    for (; arg[i]; i++)
    {
        if (!isdigit(arg[i]))
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    n = atoi(arg);

    new = malloc(sizeof(stack_t));
    if (!new)
        exit(EXIT_FAILURE);

    new->n = n;
    new->next = NULL;
    new->prev = NULL;

    /* =========================
       STACK MODE (LIFO)
       ========================= */
    if (mode == 0)
    {
        new->next = *stack;

        if (*stack)
            (*stack)->prev = new;

        *stack = new;
        return;
    }

    /* =========================
       QUEUE MODE (FIFO)
       ========================= */
    if (!*stack)
    {
        *stack = new;
        return;
    }

    temp = *stack;

    while (temp->next)
        temp = temp->next;

    temp->next = new;
    new->prev = temp;
}
