#ifndef STACK_H
#define STACK_H
#define EMPTY -1
#define TRUE 1
#define FALSE 0

typedef int(* t_visit)(int);
typedef int t_bool;
typedef struct s_stack
{
	int	*elements;
	int	top;
    t_bool initialized;
}	t_stack;

int		size(const t_stack *stack);

void    push(t_stack *stack, int element);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

t_stack	create_stack(int stack_size);
void	destroy_stack(t_stack *stacks);
void    populate_stack(t_stack *stack, const int *elements, int num_elements);
void	visit_elements(t_stack *stack, t_visit visit);

#endif