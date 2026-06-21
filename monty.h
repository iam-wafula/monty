#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* STACK STRUCT */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* OPCODE STRUCT */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* GLOBAL MODE */
extern int mode;

/* CORE */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* MODE */
void set_stack_mode(stack_t **stack, unsigned int line_number);
void set_queue_mode(stack_t **stack, unsigned int line_number);

/* EXECUTOR */
void execute(char *opcode, char *arg, stack_t **stack, unsigned int line_number);

#endif
