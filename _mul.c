#include "monty.h"

/**
 * handle_mul - multiplies first two elements
 * @head: pointer to first element
 * @line_num: number of line
*/

void handle_mul(stack_t **head, unsigned int line_num)
{
	stack_t *top, *second;
	unsigned int result;

	if (!(*head) || !(head)->next)
		handle_err("can't mul,", "stack too short", line_num, head);
	top = *head;
	second = (*head)->next;

	result = top->n / second->n;
	second->prev = top->prev;
	top->prev->next = second;
	free(top);
	second->n = result;
	*head = second;
}
