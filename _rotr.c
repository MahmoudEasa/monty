#include "monty.h"

/**
 * handle_rotr - rotate stack to bottom
 * @head: a pointer to first node
 * @line_num: integer input
 */

void handle_rotr(stack_t **head, unsigned int line_num)
{
	stack_t *last;
	void(line_num);

	if (!(*head) || !(*head)->next)
		return;
	last = *head;
	while (last)
	{
		last = last->next;
		if (last == *head)
			break;
	}
	last->prev->next = *head;
	last->next = *head->next;
	last->prev = *head;
	(*head)->prev = last->prev;
	*head = last;
}

