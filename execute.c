#include "monty.h"

/**
 * get_op - matches opcode to function
 * @opcode: command string
 *
 * Return: pointer to function or NULL
 */
void (*get_op(char *opcode))(stack_t **, unsigned int)
{
    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"swap", swap},
        {"add", add},
        {"nop", nop},
        {"div", _div},
        {"mul", mul},
        {NULL, NULL}
    };

    int i = 0;

    while (ops[i].opcode)
    {
        if (strcmp(ops[i].opcode, opcode) == 0)
            return (ops[i].f);
        i++;
    }

    return (NULL);
}

/**
 * execute_file - reads and executes Monty bytecode file
 * @filename: file path
 * @stack: pointer to stack
 */
void execute_file(char *filename, stack_t **stack)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    char *opcode;
    void (*func)(stack_t **, unsigned int);

    file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (getline(&line, &len, file) != -1)
    {
        line_number++;

        opcode = strtok(line, " \t\n");

        if (!opcode || opcode[0] == '#')
            continue;

        func = get_op(opcode);

        if (!func)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n",
                    line_number, opcode);
            exit(EXIT_FAILURE);
        }

        func(stack, line_number);
    }

    free(line);
    fclose(file);
}
