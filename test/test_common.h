#ifndef TEST_COMMON_H
# define TEST_COMMON_H
# include <time.h>

typedef enum e_stack_functions
{
    PUSH = 0,
    SWAP = 1,
    ROTATE = 2,
    REVERSE_ROTATE = 3
} t_stack_functions;

typedef struct s_time
{
	clock_t start;
   	clock_t stop;
}	t_time;

int plus_2(int element);
double timedifference_msec(t_time time);

#endif