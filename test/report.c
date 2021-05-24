#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DARK_GREEN "\e[1;38;5;17m\e[48;5;36m\e[4m"
#define LIGHT_GREEN "\e[1;38;5;17m\e[48;5;79m\e[4m"
#define RESET "\e[0m"
#define MAX_LINE_LENGTH 50
typedef int t_bool;
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
    RANDOM = 7,
    NUM_TESTS = 8,
}   t_test;

typedef struct s_fields
{
    char * test_name;
    double run_time;
} t_fields;

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

static const char **get_test_types()
{
    static const char *test_types[] = {
                                    "SWAP",
                                    "REVERSE ROTATE",
                                    "ROTATE",
                                    "SIZE",
                                    "PUSH",
                                    "POPULATE",
                                    "VISIT",
                                    "RANDOM",
                                    "NUM_TESTS",
                                };
    return (test_types);
}

static t_fields get_fields(char* line)
{
    char *test_name = strtok(line, ",");
    char *test_name_cpy = strdup(test_name);
    char *run_time = strtok(NULL, ",\n");

    t_fields fields = {
        .test_name = test_name_cpy,
        .run_time = atof(run_time),
    };

    return (fields);
}

t_test get_test_type(char *name)
{
    int i = 0;
    while (i < NUM_TESTS)
    {
        if (strcmp(name, get_test_types()[i]) == 0)
            return (i);
        ++i;
    }
    return (0);
}

static t_bool is_same_test_field(t_fields array, t_fields linked)
{
    return (strcmp(array.test_name, linked.test_name) == 0);
}

static void cleanup(const t_fields *array, const t_fields *linked)
{
    free(array->test_name);
    free(linked->test_name);
}

void generate_report(FILE *array_fd, FILE *linked_fd)
{
    print_header();
    char line_array[MAX_LINE_LENGTH];
    char line_linked[MAX_LINE_LENGTH];

    while (fgets(line_array, MAX_LINE_LENGTH, array_fd) && fgets(line_linked, MAX_LINE_LENGTH, linked_fd))
    {
        const t_fields array = get_fields(line_array);
        const t_fields linked = get_fields(line_linked);
        if (is_same_test_field(array, linked))
            print_line(array.test_name, array.run_time, linked.run_time);
        cleanup(&array, &linked);
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