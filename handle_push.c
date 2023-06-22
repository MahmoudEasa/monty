#include "monty.h"

/**
 * handle_push - handle push in stack and queue
 * @head: the head of the linked list
 * @line_num: the line number where the instruction appears
 */

void handle_push(stack_t **head, unsigned int line_num)
{
	if (strcmp(monty.format_data, "stack") == 0)
		_push(head, line_num);
	else if (strcmp(monty.format_data, "queue") == 0)
		_insert(head, line_num);

}

