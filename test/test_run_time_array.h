#ifndef TEST_RUN_TIME_ARRAY_H
 #define TEST_RUN_TIME_ARRAY_H

# include <stack.h>
# include "test_common.h"

typedef void(* t_process)(t_stack *);
typedef void(* t_command)(t_stack *, int);
typedef void(* t_command_populate)(t_stack *, const int *, int);

double execute_command(int times, t_command command);
double execute_populate(int num_elements, t_command_populate command);
double run_test(int num_elements, double times_to_repeate, t_process process);
double run_size_test(int num_elements, double times_to_repeate);
double run_visit_test(int num_elements, double times_to_repeate);
double run_push_test(double times_to_repeate);
double run_populate_test(int num_elements, double times_to_repeate);
double execute_random_function(t_stack *stack);
double run_random_test(int num_elements, double times_to_repeate);

#endif