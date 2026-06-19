# Monty Interpreter

This project implements a Monty bytecode interpreter using C.

## Description

Monty is a scripting language that relies on a unique stack with specific instructions to manipulate it.

This interpreter supports the following opcodes:

- push
- pall
- pint
- pop
- swap
- add
- nop
- div
- mul

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
