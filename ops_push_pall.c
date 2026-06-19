#include "monty.h"

/**
 * is_number - checks if string is valid integer
 */
int is_number(char *str)
{
    int i = 0;

    if (!str || str[0] == '\0')
        return (0);

    if (str[0] == '-')
        i++;

    for (; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return (0);
    }

    return (1);
}

/**
 * push - pushes value to stack
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " \t\n");

    if (!arg || !is_number(arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    push_node(stack, atoi(arg));
}

/**
 * pall - prints stack
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *tmp = *stack;
    (void)line_number;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}
