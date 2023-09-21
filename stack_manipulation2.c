#include "monty.h"

/**
 * s_swap - swaps the top two elements of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_swap(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	temp = (*h)->next;
	if (temp->next != NULL)
		temp->next->prev = *h;
	(*h)->next = temp->next;
	(*h)->prev = temp;
	temp->prev = NULL;
	temp->next = *h;
	(*h) = temp;

}

/**
 * s_rotl - rotates the stack to the top.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_rotl(stack_t **h, unsigned int line_num)
{
	(void) line_num;
	(void) h;
}


/**
 * s_rotr - rotates the stack to the bottom.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_rotr(stack_t **h, unsigned int line_num)
{
	(void) line_num;
	(void) h;
}
