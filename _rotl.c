#include "monty.h"

/**
 * handle_rotl - rotate stack
 * @head: a pointer to first node
 * @line_num: integer input
 */

void handle_rotl(stack_t **head, unsigned int line_num)
{
	stack_t *top, *last;

	(void)line_num;
	if (!(*head) || !(*head)->next)
		return;
	top = (*head)->next;
	last = *head;

	while (last->next)
	{
		last = last->next;
		if (last == *head)
			break;
	}
	top->prev = (*head)->prev;
	last->next = *head;
	(*head)->next = top;
	(*head)->prev = last;
	*head = top;
}

