#include "monty.h"

void free_stack(stack_t **stack);

int main(int argc, char **argv)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 1;
    stack_t *stack = NULL;
    char *opcode;
    char *arg;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        opcode = strtok(line, " \t\n");
        arg = strtok(NULL, " \t\n");

        if (opcode && opcode[0] != '#')
        {
            execute(opcode, arg, &stack, line_number);
        }

        line_number++;
    }

    free(line);
    fclose(file);
    free_stack(&stack);

    return (0);
}
