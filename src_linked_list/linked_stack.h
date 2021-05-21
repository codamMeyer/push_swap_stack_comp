#ifndef LINKED_STACK_H
#define LINKED_STACK_H
typedef int(* t_visit)(int);
typedef struct s_linked_stack
{
    int element;
    struct s_linked_stack *next;
} t_linked_stack;

int             size(const t_linked_stack *stack);

void            push(t_linked_stack **stack, int element);
void            swap(t_linked_stack **stack);
void	        rotate(t_linked_stack **stack);
void	        reverse_rotate(t_linked_stack **stack);

t_linked_stack  *create_stack();
void            destroy_stack(t_linked_stack **stack);
void            populate_stack(t_linked_stack **stack, const int *elements, int num_elements);
void	        visit_elements(t_linked_stack *stack, t_visit visit);


#endif