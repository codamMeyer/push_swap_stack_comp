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

static void print_run_time(double run_time, double times)
{
    printf("%saverage time: %f ms ", BYELLOW,  run_time / times);
}

CTEST(push, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "PUSH";
    double run_time = run_push_test(TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(populate, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "POPULATE";
    double run_time = run_populate_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
}

CTEST(size, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "SIZE";
    double run_time = run_size_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(visit, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "VISIT";
    double run_time = run_visit_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);\
}

CTEST(rotate, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "ROTATE";
    double run_time = run_test(NUM_ELEMENTS, TIMES, rotate);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(reverse_rotate, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "REVERSE ROTATE";
    double run_time = run_test(NUM_ELEMENTS, TIMES, reverse_rotate);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(swap, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "SWAP";
    double run_time = run_test(NUM_ELEMENTS, TIMES, swap);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / TIMES);
    fclose(fd);
}

CTEST(random_movements, test)
{
    FILE * fd = fopen(FILE_NAME, "a");
    const char *test_name = "RANDOM";
    double run_time = run_random_test(NUM_ELEMENTS, TIMES);
    print_run_time(run_time, TIMES);
    fprintf(fd, "%s,%f\n", test_name, run_time / (TIMES));
    fclose(fd);
}