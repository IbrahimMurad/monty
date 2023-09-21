#include "monty.h"

/**
 * run_opcode - runs all the opcodes but push, nop, stack, queue
 * @op_code: a string the holds the opcode
 * @line_num: the line number
 *
 * Return: nothing
*/

int run_opcode(char *op_code, unsigned int line_num)
{
	int i, rtrn_value = 0;
	instruction_t s_instructs[] = {
		{"add", s_add},
		{"sub", s_sub},
		{"mul", s_mul},
		{"div", s_div},
		{"mod", s_mod},
		{"pall", s_pall},
		{"pint", s_pint},
		{"pchar", s_pchar},
		{"pstr", s_pstr},
		{"pop", s_pop},
		{"swap", s_swap},
		{"rotl", s_rotl},
		{"rotr", s_rotr},
		{NULL, NULL}
	};

	for (i = 0; s_instructs[i].opcode != NULL; i++)
	{
		if (strcmp(s_instructs[i].opcode, op_code) == 0)
		{
			rtrn_value = check_error(i, s_instructs[i].opcode, line_num);
			if (rtrn_value == R_SUCCESS)
				s_instructs[i].f(&head, line_num);
		}
	}
	return (rtrn_value);
}


int check_error(int i, char *op_code, unsigned int line_num)
{
	int rtrn_value = 0;

	switch (i)
	{
		case S_ADD:
		case S_SUB:
		case S_MUL:
		case S_SWAP:
			if (head == NULL || head->next == NULL)
			{
				fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op_code);
				return (R_FAILURE);
			}
			break;
		case S_DIV:
		case S_MOD:
			if (head == NULL || head->next == NULL)
			{
				fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op_code);
				return (R_FAILURE);
			}
			if (head->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_num);
				return (R_FAILURE);
			}
			break;		
		default:
			rtrn_value = check_error2(i, line_num);
	}
	return (rtrn_value);
}

int check_error2(int i, unsigned int line_num)
{	
	switch (i)
	{
		case S_POP:
			if (head == NULL)
			{
				fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
				return (R_FAILURE);
			}
			break;
		case S_PINT:
			if (head == NULL)
			{
				fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
				return (R_FAILURE);
			}
			break;
		case S_PCHAR:
			if (head == NULL)
			{
				fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
				return (R_FAILURE);
			}
			if (head->n < 0 || head->n > 127)
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
				return (R_FAILURE);
			}
			break;
		default:
			return (R_SUCCESS);
	}
	return (R_SUCCESS);
}

/**
 * free_list - frees the stack
 * Retrun: Nothing
*/

void free_list(void)
{
	stack_t *temp;

	temp = head;
	while (temp)
	{
		head = head->next;
		free(temp);
		temp = head;
	}
}
