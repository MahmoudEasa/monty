#include "monty.h"

/**
 * handle_pstr - ?????????
 * @head: a pointer to first node
 * @line_num: integer input
 */

void handle_pstr(stack_t **head, unsigned int line_num)
{
	if (!head || !(*head))
		handle_err("can't pchar,", "stack empty", line_num, head, NULL);
	if ((*head)->n < 0 || (*head)->n > 127)
		handle_err("can't pchar,", "value out of range", line_num, head, NULL);

	printf("pstr: %d\n", (*head)->n);
}

