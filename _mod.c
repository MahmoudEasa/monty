#include "monty.h"

/**
 * handle_mod - rest of divition
 * @head: a pointer to first node
 * @line_num: number of line
*/

void handle_mod(stack_t **head, unsigned int line_num)
{
	stack_t *top, *second;
	unsigned int result;

	if (!(*head) || !(*head)->next)
		handle_err("can't mod,", "stack too short", line_num, head);
	top = *head;
	second = (*head)->next;

	if (top->n == 0)
		handle_err("division by", "zero", line_num, head);
	result = second->n % top->n;
	second->prev = top->prev;
	top->prev->next = second;
	free(top);
	second->n = result;
	*head = second;
}
