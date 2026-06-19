#include "monty.h"

/**
 * main - entry point
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    execute_file(argv[1], &stack);
    free_stack(stack);

    return (0);
}
