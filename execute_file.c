#include "monty.h"

/**
 * execute_file - handle command line from the file
 * @inst_arr: array of instructions
 */

void execute_file(instruction_t *inst_arr)
{
	int found = 0;
	unsigned int line_num = 0;
	char buf[MAX_LINE_LENGTH], *token;
	stack_t *head = NULL;
	instruction_t *inst_help;

	while ((fgets(buf, MAX_LINE_LENGTH, monty.file)) != NULL)
	{
		monty.data = NULL;
		found = 0;
		line_num++;
		token = strtok(buf, " \n\t\a\b");
		if (!token && strchr(buf, '\n') == NULL)
			continue;
		if (!token || *token == '#' || strcmp(token, "nop") == 0)
			continue;
		inst_help = inst_arr;
		while ((inst_help->opcode))
		{
			if (strcmp(token, inst_help->opcode) == 0)
			{
				found = 1;
				if (strcmp(token, "push") == 0)
				{
					token = strtok(NULL, " \n\t\a\b");
					check_is_digit(token, line_num, &head);
				}
				monty.data = token;
				inst_help->f(&head, line_num);
				break;
			}
			inst_help++;
		}
		if (found == 0)
			handle_err("unknown instruction", inst_help->opcode, line_num, &head);
	}
	if (head)
		free_list(&head);
}

/**
 * check_is_digit - check if argument 2 include digit
 * @token: string
 * @line_num: unsigned int
 * @head: the head of the linked list
 */

void check_is_digit(char *token, unsigned int line_num,	stack_t **head)
{
	int i;

	if (!token)
		handle_err("usage: push", "integer", line_num, head);

	for (i = 0; token[i]; i++)
		if (!isdigit(token[i]) && token[0] != '-')
			handle_err("usage: push", "integer", line_num, head);
}

