#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DARK_GREEN "\e[1;38;5;17m\e[48;5;36m\e[4m"
#define LIGHT_GREEN "\e[1;38;5;17m\e[48;5;79m\e[4m"
#define RESET "\e[0m"

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ",");
            tok && *tok;
            tok = strtok(NULL, ",\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

typedef enum e_stack_type
{
    ARRAY = 0,
    LINKED_LIST
}   t_stack_type;

typedef enum e_test
{
    SWAP = 0,
    REVERSE_ROTATE = 1,
    ROTATE = 2,
    SIZE = 3,
    PUSH = 4,
    POPULATE = 5,
    VISIT = 6,
    NUM_TESTS = 7,
}   t_test;

typedef struct s_run_time
{
    t_test test;
    double array;
    double linked;
} t_run_time;

static void print_header()
{
    printf("\n%s%s", LIGHT_GREEN, "    TEST NAME    \e[0m");
    printf("%s%s", DARK_GREEN, "     ARRAY (ms)   \e[0m");
    printf("%s%s", LIGHT_GREEN, "  LINKED LIST (ms) \e[0m");
    printf("%s%s", DARK_GREEN, "NORMALIZED (LIST/ARRAY)\e[0m\n");
}

static void print_line(const char * test_name, double array_run_time, double linked_run_time)
{
    printf("%s %-16s\e[0m", LIGHT_GREEN, test_name);
    printf("%s%17f \e[0m", DARK_GREEN, array_run_time);
    printf("%s%18f \e[0m", LIGHT_GREEN, linked_run_time);
    printf("%s%22.2f \e[0m\n", DARK_GREEN, linked_run_time / array_run_time);
}

t_test get_test_type(char *name)
{
    const char *test_type[] = {
                                    "SWAP",
                                    "REVERSE ROTATE",
                                    "ROTATE",
                                    "SIZE",
                                    "PUSH",
                                    "POPULATE",
                                    "VISIT",
                                    "NUM_TESTS",
                                };
    int i = 0;
    while (i < NUM_TESTS)
    {
        if (strcmp(name, test_type[i]) == 0)
            return (i);
        ++i;
    }
    return (0);
}


void generate_report(FILE *array_fd, FILE *linked_fd)
{
    const char *test_type[] = {
                                    "SWAP",
                                    "REVERSE ROTATE",
                                    "ROTATE",
                                    "SIZE",
                                    "PUSH",
                                    "POPULATE",
                                    "VISIT",
                                    "NUM_TESTS",
                                };

    print_header();
    t_run_time run_time = {.array = 0, .linked = 0, .test = 0};


    char line_array[50];
    char line_linked[50];

    while (fgets(line_array, 50, array_fd) && fgets(line_linked, 50, linked_fd))
    {
        char* arr_test = strdup(line_array);
        char* linked_test = strdup(line_linked);
        char* arr_value = strdup(line_array);
        char* linked_value = strdup(line_linked);
        if (strcmp(getfield(arr_test, 1), getfield(linked_test, 1)) == 0)
        {       
            run_time.test = get_test_type(arr_test);
            run_time.array = atof(getfield(arr_value, 2));
            run_time.linked = atof(getfield(linked_value, 2));
        }
        free(arr_test);
        free(linked_test);
        free(arr_value);
        free(linked_value);
        print_line(test_type[run_time.test], run_time.array, run_time.linked);
    }
    printf("\n");
}


int main()
{
    FILE* array_fd = fopen("array.txt", "r");
    FILE* linked_fd = fopen("linked_list.txt", "r");
    generate_report(array_fd, linked_fd);
    fclose(array_fd);
    fclose(linked_fd);
}