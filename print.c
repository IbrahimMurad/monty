#include "monty.h"

/**
 * s_pall - prints all the values on the stack,
 * starting from the top of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_pall(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	temp = *h;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}


/**
 * s_pint - prints the value at the top of the stack, followed by a new line.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_pint(stack_t **h, unsigned int line_num)
{
	(void) line_num;
	printf("%d\n", (*h)->n);
}

/**
 * s_pchar - prints the char at the top of the stack, followed by a new line.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_pchar(stack_t **h, unsigned int line_num)
{
	(void) line_num;
	printf("%c\n", (*h)->n);
}

/**
 * s_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_pstr(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	temp = *h;
	while (temp)
	{
		if (temp->n > 0 && temp->n < 255)
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
		else
		{
			break;
		}
	}
	printf("\n");
}
