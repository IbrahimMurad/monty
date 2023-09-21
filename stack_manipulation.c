#include "monty.h"

/**
 * s_push - pushes an element to the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_push(stack_t **h, unsigned int line_num)
{
	(void) line_num;
	(*h)->next = head;
	(*h)->prev = NULL;
	head->prev = *h;
	head = *h;
}


/**
 * q_push - pushes an element to the queue.
 * @h: the address of a pointer to the front node of the queue
 * @line_num: the line number
 *
 * Return: Nothing
*/

void q_push(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = *h;
	(*h)->next = NULL;
	(*h)->prev = temp;
}


/**
 * s_pop - removes the top element of the stack.
 * @h: the address of a pointer to the head node of the stack
 * @line_num: the line number
 *
 * Return: Nothing
*/

void s_pop(stack_t **h, unsigned int line_num)
{
	stack_t *temp;

	(void) line_num;
	temp = *h;
	*h = temp->next;
	(*h)->prev = NULL;
	free(temp);
}
