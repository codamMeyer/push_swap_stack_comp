#include "ctest.h"
#include <fcntl.h>
#include <stdio.h>
#define BYELLOW "\033[01;33m"
#ifdef LINKED
# define STACK_TYPE "linked list"
# define FILE_NAME "linked_list.txt"
# include "test_run_time_linked.h"
#else
# define STACK_TYPE "array"
# define FILE_NAME "array.txt"
# include "test_run_time_array.h"
#endif

#define TIMES 100000.0
#define NUM_ELEMENTS 2000

static void print_run_time(float run_time, double times)
{
    printf("%saverage time: %f ms ", BYELLOW,  run_time / times);
}

CTEST(push_test, 100000_time)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "PUSH";
    float run_time = run_push_test(TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(populate_test, many_times)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "POPULATE";
    float run_time = run_populate_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
}

CTEST(size_test, many_times)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "SIZE";
    float run_time = run_size_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(visit_test, 100000_time)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "VISIT";
    float run_time = run_visit_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);\
}

CTEST(rotate_test, many_times)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "ROTATE";
    float run_time = run_test(NUM_ELEMENTS, TIMES, rotate);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(reverse_rotate_test, many_times)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "REVERSE ROTATE";
    float run_time = run_test(NUM_ELEMENTS, TIMES, reverse_rotate);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(swap_test, many_times)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "SWAP";
    float run_time = run_test(NUM_ELEMENTS, TIMES, swap);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}