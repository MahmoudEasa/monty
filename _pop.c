#include "monty.h"

/**
 * handle_pop - a function that pop first node
 * @head: pointer to first node
 * @line_num: number of input line
*/

void handle_pop(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (!(*head) || !head)
		handle_err("can't pop", "an empty stack", line_num, head);
	if ((*head)->next == *head)
	{
		free(*head);
		*head = NULL;
		return;
	}
	temp = (*head)->next;
	temp->prev = (*head)->prev;
	(*head)->prev->next = temp;
	(*head)->prev->prev = temp;
	free(*head);
	*head = temp;
}
