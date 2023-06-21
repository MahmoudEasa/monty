#include "monty.h"

/**
 * main - Entry point
 * @argc: count of arguements
 * @argv: values of arguments
 *
 * Return: return 0 if success
*/

int main(int argc, char **argv)
{
	int i = 0, j = 0, found = 0, len;
	unsigned int line_num = 0;
	char buf[255], *token;
	FILE *fp;
	stack_t *head = NULL;
	instruction_t inst_arr[SIZE_INST] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{NULL, NULL},
	};

	(void)data;
	if (argc != 2)
		handle_err("USAGE: monty", "file", 0);
	fp = fopen(argv[1], "r");
	if (!fp)
		handle_err("Error: Can't open file", argv[1], 0);
	while ((fgets(buf, 255, fp)) != NULL)
	{
		data = NULL;
		found = 0;
		i = 0;
		line_num++;
		len = strlen(buf);
		if (buf[len - 1] == '\n')
			buf[len - 1] = '\0';
		token = strtok(buf, " ");
		if (!token || *token == '#')
			continue;
		while ((inst_arr[i].opcode))
		{
			if (strcmp(token, inst_arr[i].opcode) == 0)
			{
				found = 1;
				token = strtok(NULL, " ");
				if (token)
				{
					for (j = 0; token[j]; j++)
					{
						if (!isdigit(token[j]))
							handle_err("usage: push", "integer", line_num);
					}
				}
				data = token;
				inst_arr[i].f(&head, line_num);
				break;
			}
			i++;
		}
		if (found == 0)
			handle_err("unknown instruction", inst_arr[i].opcode, line_num);
	}
	fclose(fp);
	return (0);
}

/**
 * handle_err - a function that handle err
 * @message: input message
 * @str: input string
 * @line_num: input unsigned int
*/
void handle_err(char *message, char *str, int line_num)
{
	if (!line_num)
		fprintf(stderr, "%s %s\n", message, str);
	else
		fprintf(stderr, "L%u: %s %s\n", line_num, message, str);
	exit(EXIT_FAILURE);
}
