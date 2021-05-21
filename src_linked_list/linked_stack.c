#include "linked_stack.h"
#include <stdlib.h>
#define STACK_TYPE "LINKED LIST"


static t_linked_stack  *create_new_element(int element)
{
    t_linked_stack *new = malloc(sizeof(t_linked_stack));
    if (!new)
        return (NULL);
    new->element = element;
    new->next = NULL;
    return (new);
}

static t_linked_stack	*get_last_element(t_linked_stack *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

int size(const t_linked_stack *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (size);
	while (stack != NULL)
	{
		++size;
		stack = stack->next;
	}
	return (size);
}

void	push(t_linked_stack **stack, int element)
{
	t_linked_stack *new = create_new_element(element);

	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	swap(t_linked_stack **stack)
{
	t_linked_stack *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	rotate(t_linked_stack **stack)
{
    if (*stack == NULL || (*stack)->next == NULL)
		return ;
	t_linked_stack *old_head = *stack;
	t_linked_stack *new_head = (*stack)->next;
    t_linked_stack *tail = get_last_element(*stack);

    tail->next = old_head;
    old_head->next = NULL;
    (*stack) = new_head;
}

void reverse_rotate(t_linked_stack **stack) 
{
    if (*stack == NULL || (*stack)->next == NULL)
		return ;

    t_linked_stack	*old_head = *stack;
    t_linked_stack	*new_head = *stack;
	t_linked_stack	*new_tail = *stack;

	while (new_head->next != NULL)
	{
		new_head = new_head->next;
		if (new_head->next != NULL)
			new_tail = new_tail->next;
	}
	if (new_head->next == NULL)
	{
		new_head->next = old_head;
		new_tail->next = NULL;
	}
	*stack = new_head;
}

t_linked_stack* create_stack() 
{
    return (NULL);
}


void populate_stack(t_linked_stack **stack, const int *elements, int num_elements)
{
    int i = num_elements - 1;

    while (i >= 0)
    {
        push(stack, elements[i]);
		--i;
    }
}

void destroy_stack(t_linked_stack **stack)
{
	t_linked_stack	*tmp;

	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = tmp->next;
		free(tmp);
	}
	*stack = NULL;
}


void	visit_elements(t_linked_stack *stack, t_visit visit)
{
	while (stack != NULL)
	{
		stack->element = visit(stack->element);
		stack = stack->next;
	}
}