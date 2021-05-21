#ifndef TEST_RUN_TIME_LINKED_H
#define TEST_RUN_TIME_LINKED_H

#include <linked_stack.h>
#include "test_common.h"
#include <stdio.h>

typedef void(* t_process)(t_linked_stack **);
typedef void(* t_command)(t_linked_stack **, int);
typedef void(* t_command_populate)(t_linked_stack **, const int *, int);

float execute_command(int times, t_command command)
{
    t_time time;
    t_linked_stack *stack = create_stack();
    
    time.start = clock();
    for (int i = 0; i < times; ++i)
        command(&stack, 1);
    time.stop = clock();

    const double run_time = timedifference_msec(time);
    destroy_stack(&stack);
    return (run_time);
};

float execute_populate(int num_elements, t_command_populate command)
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
#endif