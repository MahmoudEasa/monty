#include "monty.h"

/**
 * _insert - insert node in the queue
 * @head: a pointer to first node
 * @line_num: integer input
 */

void _insert(stack_t **head, unsigned int line_num)
{
	stack_t *new_node;
	int num;

	if (!(monty.data))
		handle_err("usage: push", "integer", line_num, head);

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
		handle_err("Error: malloc", "failed", 0, head);

	num = atoi(monty.data);
	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;

	if (!(*head))
		*head = new_node;
	else if (!(*head)->next)
	{
		(*head)->next = new_node;
		(*head)->prev = new_node;
		new_node->prev = *head;
	}
	else
	{
		new_node->prev = (*head)->prev;
		(*head)->prev->next = new_node;
		(*head)->prev = new_node;
	}
}

