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
	FILE *fp;
	instruction_t inst_arr[SIZE_INST] = {
		{"push", handle_push},
		{"pall", handle_pall},
		{"pint", handle_pint},
		{"pchar", handle_pchar},
		{"pstr", handle_pstr},
		{"rotl", handle_rotl},
		{"rotr", handle_rotr},
		{"stack", handle_stack},
		{"queue", handle_queue},
		{NULL, NULL},
	};

	monty.data = NULL;
	monty.file = NULL;

	if (argc == 1 || argc > 2)
		handle_err("USAGE: monty", "file", 0, NULL);
	fp = fopen(argv[1], "r");
		if (!fp)
			handle_err("Error: Can't open file", argv[1], 0, NULL);

		monty.file = fp;
		execute_file(inst_arr);
	fclose(fp);
	return (0);
}

/**
 * handle_err - a function that handle err
 * @message: input message
 * @str: input string
 * @line_num: input unsigned int
 * @head: the head of the linked list
*/

void handle_err(char *message, char *str, int line_num,	stack_t **head)
{
	if (!line_num)
		fprintf(stderr, "%s %s\n", message, str);
	else
		fprintf(stderr, "L%u: %s %s\n", line_num, message, str);

	free_list(head);
	if (monty.file)
		fclose(monty.file);
	exit(EXIT_FAILURE);
}

