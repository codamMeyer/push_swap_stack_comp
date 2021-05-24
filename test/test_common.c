#include "test_common.h"

int plus_2(int element)
{
    return (element + 2);
}

double timedifference_msec(t_time time)
{
    return (double)(time.stop - time.start) / CLOCKS_PER_SEC * 1000.0;
}
