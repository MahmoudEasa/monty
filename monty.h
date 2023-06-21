#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define SIZE_INST 4

char *data;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void handle_err(char *message, char *str, int line_num, stack_t **head);
void handle_push(stack_t **head, unsigned int line_num);
void handle_pall(stack_t **head, unsigned int line_num);
void handle_pint(stack_t **head, unsigned int line_num);
void execute_file(FILE *fp, instruction_t *inst_arr);
void check_is_digit(char *token, unsigned int line_num, stack_t **head);
void free_list(stack_t **head);

#endif /* MONTY_H */

