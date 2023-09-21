#include "monty.h"

/**
 * s_add - adds the top two elements of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_add(stack_t **h, unsigned int line_num)
{
	int a, b;

	a = (*h)->n;
	s_pop(h, line_num);
	b = (*h)->n;
	(*h)->n = a + b;
}

/**
 * s_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_sub(stack_t **h, unsigned int line_num)
{
	int a, b;

	a = (*h)->n;
	s_pop(h, line_num);
	b = (*h)->n;
	(*h)->n = b - a;
}


/**
 * s_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_mul(stack_t **h, unsigned int line_num)
{
	int a, b;

	a = (*h)->n;
	s_pop(h, line_num);
	b = (*h)->n;
	(*h)->n = b * a;
}

/**
 * s_div - divides the second top element of the stack
 * by the top element of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_div(stack_t **h, unsigned int line_num)
{
	int a, b;

	a = (*h)->n;
	s_pop(h, line_num);
	b = (*h)->n;
	(*h)->n = b / a;
}

/**
 * s_mod - computes the rest of the division
 * of the second top element of the stack by the top element of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_mod(stack_t **h, unsigned int line_num)
{
	int a, b;

	a = (*h)->n;
	s_pop(h, line_num);
	b = (*h)->n;
	(*h)->n = b % a;
}
