#include "test_run_time_linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double execute_command(int times, t_command command)
{
    t_time time;
    t_linked_stack *stack = create_stack();
    
    time.start = clock();
    for (int i = 0; i < times; ++i)
        command(&stack, i);
    time.stop = clock();

    const double run_time = timedifference_msec(time);
    destroy_stack(&stack);

    return (run_time);
};

double execute_populate(int num_elements, t_command_populate command)
{
    t_time time;
    t_linked_stack *stack = create_stack();
    int elements[num_elements];

    for (int i = 0; i < num_elements; ++i)
        elements[i] = i;

    time.start = clock();
    command(&stack, elements, num_elements);
    time.stop = clock();
    const double run_time = timedifference_msec(time);
    destroy_stack(&stack);

    return (run_time);
};

double run_test(int num_elements, double times_to_repeate, t_process process)
{
    double run_time = 0.0;
    t_linked_stack *stack = create_stack();
    int elements[num_elements];
    for (int i = 0; i < num_elements; ++i)
        elements[i] = i;
    populate_stack(&stack, elements, num_elements);

    t_time time;
    for (int i = 0; i < times_to_repeate; ++i)
    {
        push(&stack, 6);
        time.start = clock();
        process(&stack);
        time.stop = clock();
        run_time += timedifference_msec(time);
    }
    destroy_stack(&stack);
    return (run_time);
}

double run_size_test(int num_elements, double times_to_repeate)
{
    double run_time = 0.0;
    t_linked_stack *stack = create_stack();
    int elements[num_elements];
    for (int i = 0; i < num_elements; ++i)
        elements[i] = i;
    populate_stack(&stack, elements, num_elements);

    t_time time;
    for (int i = 0; i < times_to_repeate; ++i)
    {
        time.start = clock();
        size(stack);
        time.stop = clock();
        run_time += timedifference_msec(time);
    }
    destroy_stack(&stack);
    return (run_time);
}

double run_visit_test(int num_elements, double times_to_repeate)
{
    double run_time = 0.0;
    t_linked_stack *stack = create_stack();
    int elements[num_elements];
    for (int i = 0; i < num_elements; ++i)
        elements[i] = i;
    populate_stack(&stack, elements, num_elements);

    t_time time;
    for (int i = 0; i < times_to_repeate; ++i)
    {
        time.start = clock();
        visit_elements(stack, plus_2);
        time.stop = clock();
        run_time += timedifference_msec(time);
    }
    destroy_stack(&stack);
    return (run_time);
}

double run_push_test(double times_to_repeate)
{
    return (execute_command(times_to_repeate, push));
}

double run_populate_test(int num_elements, double times_to_repeate)
{
    double run_time = 0.0;

    for(int i = 0; i < times_to_repeate; ++i)
        run_time += execute_populate(num_elements, populate_stack);
    return (run_time);
}

t_stack_functions get_random_func()
{
    int lower = 0, upper = 4;
    return ((rand() % (upper - lower + 1)) + lower);
}

double execute_random_function(t_linked_stack **stack)
{
    t_time time;
    t_stack_functions func = get_random_func();

    switch (func)
    {
    case SWAP:
        {
            time.start = clock();
            swap(stack);
            time.stop = clock();
            break;
        }
    case PUSH:
        {
            time.start = clock();
            push(stack, 1);
            time.stop = clock();
            break;
        }
    case ROTATE:
        {
            time.start = clock();
            rotate(stack);
            time.stop = clock();
            break;
        }
    case REVERSE_ROTATE:
        {
            time.start = clock();
            reverse_rotate(stack);
            time.stop = clock();
            break;
        }
    }
    return (timedifference_msec(time));
}

double run_random_test(int num_elements, double times_to_repeate)
{
    double run_time = 0.0;
    t_linked_stack *stack = create_stack();
    int elements[num_elements];
    for (int i = 0; i < num_elements; ++i)
        elements[i] = i;
    populate_stack(&stack, elements, num_elements);
    for (int i = 0; i < times_to_repeate; ++i)
    {
        run_time += execute_random_function(&stack);
    }
    destroy_stack(&stack);
    return (run_time);
}