#include "monty.h"

void execute(char *opcode, char *arg, stack_t **stack, unsigned int line_number)
{
    int i = 0;

    instruction_t ops[] = {
        {"push", push},
        {"pall", pall},
        {"pchar", pchar},
        {"pstr", pstr},
        {"rotl", rotl},
        {"rotr", rotr},
        {"stack", set_stack_mode},
        {"queue", set_queue_mode},
        {NULL, NULL}
    };

    (void)arg;

    while (ops[i].opcode)
    {
        if (strcmp(opcode, ops[i].opcode) == 0)
        {
            ops[i].f(stack, line_number);
            return;
        }
        i++;
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
