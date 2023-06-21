#include "monty.h"

/**
 * handle_pstr - ?????????
 * @head: a pointer to first node
 * @line_num: integer input
 */

void handle_pstr(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)line_num;

	while ((temp && (temp->n != 0) && (temp->n > 0 && temp->n <= 127)))
	{
		printf("%c", (temp)->n);
		temp = temp->next;
		if (temp == *head)
			break;
	}
	printf("\n");
}

