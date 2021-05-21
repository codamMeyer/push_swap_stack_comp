#include "stack.h"
#include <stdlib.h>
#define STACK_TYPE "ARRAY"

int		size(const t_stack *stack)
{
    return (stack->top + 1);
}

void    push(t_stack *stack, int element)
{
	++(stack->top);
	stack->elements[stack->top] = element;
}

void	swap(t_stack *stack)
{
	if (size(stack) < 2)
		return ;
	const int tmp = stack->elements[stack->top];
	stack->elements[stack->top] = stack->elements[stack->top - 1];
	stack->elements[stack->top - 1] = tmp;
}

void	rotate(t_stack *stack)
{
    int tmp;
	int i;

	if (size(stack) < 2)
		return ;
	tmp = stack->elements[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->elements[i] = stack->elements[i - 1];
		--i;
	}
	stack->elements[i] = tmp;
}

void reverse_rotate(t_stack *stack) 
{
    const int	stack_size = size(stack);

	if (stack_size < 2)
		return ;

	int tmp = stack->elements[0];
    int i = 0;
	while (i < stack_size - 1)
	{
		stack->elements[i] = stack->elements[i + 1];
		++i;
	}
	stack->elements[i] = tmp;
}

t_stack create_stack(int stack_size) 
{
    t_stack stack = {
        .elements = malloc(stack_size * sizeof(int)),
        .top = EMPTY,
        .initialized = TRUE,
    };
    if (!stack.elements)
        stack.initialized = FALSE;
    return (stack);
}

void populate_stack(t_stack *stack, const int *elements, int num_elements)
{
    int i = num_elements - 1;

    while (i >= 0)
    {
        push(stack, elements[i]);
        --i;
    }
}

void	destroy_stack(t_stack *stacks)
{
	if (stacks->initialized)
	{
		free(stacks->elements);
		stacks->elements = NULL;
	}
	stacks->initialized = FALSE;
}

void visit_elements(t_stack *stack, t_visit visit) 
{
	int i = 0;
	while (i <= stack->top)
	{
		stack->elements[i] = visit(stack->elements[i]);
		++i;
	}
}