#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list node
 * @n: integer value
 * @prev: previous node
 * @next: next node
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode mapping
 * @opcode: command string
 * @f: function pointer
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* ================= CORE OPCODES ================= */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/* ================= STACK OPS ================= */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* ================= ARITHMETIC OPS ================= */
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);

/* ================= EXECUTION ENGINE ================= */
void execute_file(char *filename, stack_t **stack);
void (*get_op(char *opcode))(stack_t **, unsigned int);

/* ================= HELPERS ================= */
int is_number(char *str);
void push_node(stack_t **stack, int n);
void free_stack(stack_t *stack);

#endif
