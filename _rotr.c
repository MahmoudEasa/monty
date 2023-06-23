#include "monty.h"

/**
 * handle_rotr - rotate stack to bottom
 * @head: a pointer to first node
 * @line_num: integer input
 */

void handle_rotr(stack_t **head, unsigned int line_num)
{
	stack_t *top;
	void(line_num);

	if (!(*head) || !(*head)->next)
		return;
	top = *head;
	while (top)
	{
		top = top->next;
		if (top == *head)
			break;
	}
	top->prev->next = top->next;
	top->next = *head;
	top->prev = *head->next;
	(*head)->prev = top;
	*head = top;
}

