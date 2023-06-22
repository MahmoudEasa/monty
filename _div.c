#include "monty.h"

/**
 * handle_div - divides second element by first
 * @head: a pointer to first element
 * @line_num: number of element
*/

void handle_div(stack_t **head, unsigned int line_num)
{
	stack_t *top, *second;
	unsigned int result;

	if (!(*head) || !(*head)->next)
		handle_err("can't div,", "stack too short", line_num, head);
	top = *head;
	second = (*head)->next;
	if (second->n == 0)
		handle_err("division by", "zero", line_num, head);
	result = second->n / top->n;
	second->prev = top->prev;
	top->prev->next = second;
	free(top);
	second->n = result;
	*head = second;
}
