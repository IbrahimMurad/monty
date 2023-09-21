#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point
 * @argc: the number of passed arguments including ./monty
 * @argv: an array of strings that hords the arguments
 * including ./monty
 * Return: 1 on success or EXIT_FAILURE on failure
*/

int main(int argc, char *argv[])
{
	FILE *m_file = NULL;
	int rtrn_value;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m_file = fopen(argv[1], "r");
	if (m_file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	rtrn_value = read_file(m_file);
	free_list();
	fclose(m_file);
	if (rtrn_value == R_SUCCESS)
		exit(EXIT_SUCCESS);
	else
		exit(EXIT_FAILURE);
}


/**
 * read_file - reads the file passed to it line by line
 * and gets the opcode from each line
 * @m_file: a file descriptor of the opened file
 *
 * Return: nothing
*/

int read_file(FILE *m_file)
{
	unsigned int line_num;
	int mode = 0, rtrn_value = 0;
	size_t n = 0;
	char *buf = NULL;

	for (line_num = 1; getline(&buf, &n, m_file) != -1; line_num++)
	{
		buf[strlen(buf) - 1] = '\0';
		rtrn_value = process_line(buf, line_num, &mode);
		if (rtrn_value == R_FAILURE)
			break;
	}
	free(buf);
	return (rtrn_value);
}

/**
 * process_line - checks the opcode in the line and runs it if found
 * @buf: a string that holds the line
 * @line_num: the line number
 * @mode: a reference to the current working mode (stack or queue)
 * Return: R_SUCCESS in no opcode found and running opcode successfully
 * or R_FAILURE if failed to run the opcode for any reason
*/

int process_line(char *buf, unsigned int line_num, int *mode)
{
	int opcode_code, rtrn_value = 0;
	char *op_code = NULL, *value_str = NULL;

	op_code = strtok(buf, " ");
	if (op_code == NULL)
		return (R_SUCCESS);
	if (op_code[0] == '#')
	{
		return (R_SUCCESS);
	}
	opcode_code = check_opcode(op_code);
	switch (opcode_code)
	{
	case 0:
		*mode = M_STACK;
		break;
	case 1:
		*mode = M_QUEUE;
		break;
	case 2:
		value_str = strtok(NULL, " ");
		rtrn_value = add_node(value_str, mode, line_num);
		break;
	case 3:
		break;	/*nod case*/
	case -1:
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
		rtrn_value = R_FAILURE;
		break;
	default:
		rtrn_value = run_opcode(op_code, line_num);
		break;
	}
	return (rtrn_value);
}


/**
 * check_opcode - checks the opcode
 * @opcode_str: the opcode an a string
 *
 * Return: an integer that indicates to the opcode
 * or -1 if wrong opcode
*/

int check_opcode(char *opcode_str)
{
	int i;
	const char *list_of_op[] = {"stack", "queue", "push", "nop", "pall", "pint",
		"pop", "swap", "add", "sub", "mul", "div", "mod", "rotl", "rotr",
		"pchar", "pstr"};

	for (i = 0; i < 17; i++)
	{
		if (strcmp(opcode_str, list_of_op[i]) == 0)
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * add_node - handles the opcode push
 * @value_str: the value (as string) to be added to the stack or the queue
 * @mode: an integer indicating to the mode, 0 for stack and 1 for queue
 * @line_num: the line number
 * Return: Nothing
*/

int add_node(char *value_str, int *mode, unsigned int line_num)
{
	int value;
	stack_t *new_node;

	if (value_str[0] == '-' && isdigit(value_str[1]))
	{
		value = -atoi(value_str + 1);
	}
	else if (isdigit(value_str[0]))
	{
		value = atoi(value_str);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		return (R_FAILURE);
	}
	new_node = (stack_t *) malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (R_FAILURE);
	}
	new_node->n = value;
	if (head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		head = new_node;
	}
	else
	{
		if (*mode == M_STACK)
		s_push(&new_node, line_num);
	else
		q_push(&new_node, line_num);
	}
	return (R_SUCCESS);
}
