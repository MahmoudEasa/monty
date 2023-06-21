#include "monty.h"

/**
 * free_list - free linked list
 * @head: the head of the linked list
 */

void free_list(stack_t **head)
{
	stack_t *temp, *help;

	if (head && *head)
	{
		temp = (*head)->next;
		while ((temp && temp != *head))
		{
			help = temp->next;
			free(temp);
			temp = help;
		}
		free(*head);
		*head = NULL;
	}
}

