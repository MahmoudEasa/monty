#include "monty.h"

/**
 * handle_pall - prints all values stat from top
 * @head: a pointer to first node
 * @line_num: numbe of line
*/
void handle_pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp = (*head);

	(void)line_num;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
		if (temp == (*head))
			break;
	}
}
