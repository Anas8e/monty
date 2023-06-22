#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>

/* Structure declarations */
typedef struct stack_s {
	 int n;
	 struct stack_s *prev;
	 struct stack_s *next;
} stack_t;

typedef struct instruction_s {
	 char *opcode;
	 void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void execute_instruction(char *instruction, unsigned int line_number, stack_t **stack);
void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void free_stack(stack_t *stack);

#endif /* MONTY_H */

