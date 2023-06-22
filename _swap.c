#include "monty.h"

/**
 * handle_swap - swap first two node
 * @head: a pointer to first node
 * @line_num: number of lines
*/

void handle_swap(stack_t **head, unsigned int line_num)
{
	stack_t *temp;

	if (!(*head) || !(*head)->next)
		handle_err("can't swap,", "stack too short", line_num, head);
	temp = *head;
	temp = (*head)->next;
	temp->prev = (*head)->prev;
	(*head)->prev->next = temp;
	(*head)->prev = temp;
	(*head)->next = temp->next;
	temp->next->prev = *head;
	temp->next = *head;
	*head = temp;
}
