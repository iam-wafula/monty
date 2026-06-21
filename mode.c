#include "monty.h"

int mode = 0;

/**
 * set_stack_mode - sets stack mode
 */
void set_stack_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    mode = 0;
}

/**
 * set_queue_mode - sets queue mode
 */
void set_queue_mode(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    mode = 1;
}
