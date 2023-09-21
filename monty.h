#ifndef MONTY
#define MONTY

#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


/* macros for the current mode */
#define M_STACK 0
#define M_QUEUE 1

/* macros for returning value */
#define R_SUCCESS 0
#define R_FAILURE 1


/* macros for error handling*/
#define S_ADD 0
#define S_SUB 1
#define S_MUL 2
#define S_DIV 3
#define S_MOD 4
#define S_PALL 5
#define S_PINT 6
#define S_PCHAR 7
#define S_PSTR 8
#define S_POP 9
#define S_SWAP 10
#define S_ROTL 11
#define S_ROTR 12

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *head;

/* basic tools*/

int read_file(FILE *);
int process_line(char *, unsigned int, int *);
int check_opcode(char *);
int add_node(char *, int *, unsigned int);
int run_opcode(char *, unsigned int);
void free_list(void);



/* node addition and removal from stack */

void s_push(stack_t **, unsigned int);
void q_push(stack_t **, unsigned int);
void s_pop(stack_t **, unsigned int);



/* stack math */

void s_add(stack_t **, unsigned int);
void s_sub(stack_t **, unsigned int);
void s_mul(stack_t **, unsigned int);
void s_div(stack_t **, unsigned int);
void s_mod(stack_t **, unsigned int);



/* stack printing*/

void s_pall(stack_t **, unsigned int);
void s_pint(stack_t **, unsigned int);
void s_pchar(stack_t **, unsigned int);
void s_pstr(stack_t **, unsigned int);



/* stack manipulation */

void s_swap(stack_t **, unsigned int);
void s_rotl(stack_t **, unsigned int);
void s_rotr(stack_t **, unsigned int);



/* error handling */
int check_error(int, char *, unsigned int);
int check_error2(int, unsigned int);

#endif /* MONTY */
