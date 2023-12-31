#include "monty.h"

/**
 * handle_pchar - prints the char at the top of the stack
 * @head: a pointer to first node
 * @line_num: integer input
 */

void handle_pchar(stack_t **head, unsigned int line_num)
{
	if (!(*head))
		handle_err("can't pchar,", "stack empty", line_num, head);
	if ((*head)->n < 0 || (*head)->n > 127)
		handle_err("can't pchar,", "value out of range", line_num, head);

	printf("%c\n", (*head)->n);
}

