#define CTEST_MAIN
#define CTEST_COLOR_OK
#include "ctest.h"
#include <stdio.h>
#define BYELLOW "\033[01;33m"
#define RESET "\033[0m"

#ifdef LINKED
# define TYPE "LINKED LIST"
#else
# define TYPE "ARRAY"
#endif

static void print_stack_type()
{
    printf("%s------------------------------------------------------------------------------------------------%s\n", BYELLOW, RESET);
    printf("  %*s\n", 50, TYPE);
    printf("%s------------------------------------------------------------------------------------------------%s\n", BYELLOW, RESET);
}

int main(int argc, const char *argv[])
{
    print_stack_type();
	return ctest_main(argc, argv);
}