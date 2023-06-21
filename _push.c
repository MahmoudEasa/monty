#include "monty.h"

/**
 * handle_push - a function that push data to linked
 * @head: a pointer to first node
 * @line_num: integer input
*/

void handle_push(stack_t **head, unsigned int line_num)
{
	stack_t *new_node;
	int num;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
		handle_err("Error: malloc", "failed", 0);
	if (!data)
		handle_err("usage: push", "integer", line_num);
	num = atoi(data);
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!(*head))
		*head = new_node;
	else if (!(*head)->next)
	{
		(*head)->next = new_node;
		(*head)->prev = new_node;
		new_node->prev = *head;
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		new_node->next = *head;
		(*head)->prev->next = new_node;
		new_node->prev = (*head)->prev;
		(*head)->prev = new_node;
		(*head) = new_node;
	}
}

