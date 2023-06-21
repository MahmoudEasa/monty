#include "monty.h"

/**
 * execute_file - handle command line from the file
 * @fp: pointer to the file
 * @inst_arr: array of instructions
 */

void execute_file(FILE *fp, instruction_t *inst_arr)
{
	int found = 0, len;
	unsigned int line_num = 0;
	char buf[255], *token;
	stack_t *head = NULL;
	instruction_t *inst_help;

	while ((fgets(buf, 255, fp)) != NULL)
	{
		data = NULL;
		found = 0;
		line_num++;
		len = strlen(buf);
		if (buf[len - 1] == '\n')
			buf[len - 1] = '\0';
		token = strtok(buf, " ");
		if (!token || *token == '#')
			continue;

		inst_help = inst_arr;
		while ((inst_help->opcode))
		{
			if (strcmp(token, inst_help->opcode) == 0)
			{
				found = 1;
				if (strcmp(token, "push") == 0)
				{
					token = strtok(NULL, " ");
					check_is_digit(token, line_num);
				}
				data = token;
				inst_help->f(&head, line_num);
				break;
			}
			inst_help++;
		}
		if (found == 0)
			handle_err("unknown instruction", inst_help->opcode, line_num);
	}
}

/**
 * check_is_digit - check if argument 2 include digit
 * @token: string
 * @line_num: unsigned int
 */

void check_is_digit(char *token, unsigned int line_num)
{
	int i;

	if (token)
		for (i = 0; token[i]; i++)
			if (!isdigit(token[i]))
				handle_err("usage: push", "integer", line_num);
}

