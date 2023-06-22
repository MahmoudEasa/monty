#include "monty.h"

/**
 * handle_sub - substract first two elements
 * @head: a pointer to first node
 * @line_num: number of line
*/

void handle_sub(stack_t **head, unsigned int line_num)
{
	stack_t *top, *second;
	unsigned int result;

	if (!(*head) || !(*head)->next)
		handle_err("can't sub,", "stack too short", line_num, head);
	top = *head;
	second = (*head)->next;
	result = second->n - top->n;
	second->prev = top->prev;
	top->prev->next = second;
	free(top);
	second->n = result;
	*head = second;
}
