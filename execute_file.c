#include "monty.h"

/**
 * execute_file - handle command line from the file
 * @inst_arr: array of instructions
 */

void execute_file(instruction_t *inst_arr)
{
	unsigned int line_num = 0;
	stack_t *head = NULL;
	instruction_t *inst_help;

	while ((fgets(monty.buf, MAX_LINE_LENGTH, monty.file)) != NULL)
	{
		monty.data = NULL;
		monty.arg = NULL;
		monty.found_arg = 0;
		line_num++;
		if (monty.buf[0] == '#')
			continue;
		monty.arg = strtok(monty.buf, " \n\t\a\b");
		if (!monty.arg && strchr(monty.buf, '\n') == NULL)
			continue;
		if (!monty.arg || (strcmp(monty.arg, "nop") == 0))
			continue;
		if (strcmp(monty.arg, "stack") == 0 || strcmp(monty.arg, "queue") == 0)
		{
			monty.format_data = monty.arg;
			continue;
		}
		inst_help = inst_arr;
		check_opcode(inst_help, line_num, &head);
		if (monty.found_arg == 0)
			handle_err("unknown instruction", monty.arg, line_num, &head);
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

/**
 * check_opcode - check opcode
 * @inst_help: struct
 * @line_num: unsigned int
 * @head: the head of the linked list
 */

void check_opcode(instruction_t *inst_help,
		unsigned int line_num, stack_t **head)
{
	while ((inst_help->opcode))
	{
		if (strcmp(monty.arg, inst_help->opcode) == 0)
		{
			monty.found_arg = 1;
			if (strcmp(monty.arg, "push") == 0)
			{
				monty.arg = strtok(NULL, " \n\t\a\b");
				while ((!monty.arg && (strchr(monty.buf, '\n') == NULL)))
				{
					fgets(monty.buf, MAX_LINE_LENGTH, monty.file);
					monty.arg = strtok(monty.buf, " \n\t\a\b");
				}
				check_is_digit(monty.arg, line_num, head);
				monty.data = monty.arg;
			}
			inst_help->f(head, line_num);
			break;
		}
		inst_help++;
	}
}

