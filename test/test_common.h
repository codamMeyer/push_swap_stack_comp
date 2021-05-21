#ifndef TEST_COMMON_H
#define TEST_COMMON_H
#include <time.h>

int plus_2(int element)
{
    return (element + 2);
}

typedef struct s_time
{
	clock_t start;
   	clock_t stop;
}	t_time;

double timedifference_msec(t_time time)
{
    return (double)(time.stop - time.start) / CLOCKS_PER_SEC * 1000.0;
}

#endif