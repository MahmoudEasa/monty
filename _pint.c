#include "monty.h"
/**
 * handle_pint - prints a value at top of stack
 * @head: a pointer to first node
 * @line_num: number of line
*/

void handle_pint(stack_t **head, unsigned int line_num)
{
	if (!(*head))
		handle_err("can't pint,", "stack empty", line_num, head, NULL);
	printf("%d\n", (*head)->n);
}
