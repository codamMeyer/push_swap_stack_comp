CC=gcc
CFLAGS= -O3 -Wall -Wextra -Werror -fsanitize=address
TEST_CFLAGS=-ggdb3 $(CFLAGS)
INC_PATH= -I./src_array -I./src_linked_list
LINKED_TEST_NAME= linked_tester
ARRAY_TEST_NAME=array_tester

ARRAY_SRC=src_array/stack.c
LINKED_LIST_SRC=src_linked_list/linked_stack.c

ARRAY_TEST_FILES=test/array_stack_test.c
LINKED_TEST_FILES=test/linked_stack_test.c

ARRAY_OBJS = $(ARRAY_SRC:.c=.o)
LINKED_LIST_OBJS = $(LINKED_LIST_SRC:.c=.o)

all: report

%.o: %.c 
	@$(CC) $(CFLAGS) $(INC_PATH) -c -o $@ $< 

run: fclean test_linked_stack test_array_stack
	@./linked_tester
	@./array_tester

test_run_time_array: $(ARRAY_OBJS)
	@rm -f array.txt
	@$(CC) $(TEST_CFLAGS) $(INC_PATH) $(ARRAY_OBJS) test/main.c test/test.c -o $(ARRAY_TEST_NAME)

test_run_time_linked: $(LINKED_LIST_OBJS)
	@rm -f linked_list.txt
	@$(CC) $(TEST_CFLAGS) $(INC_PATH) $(LINKED_LIST_OBJS) -D LINKED=1 test/main.c test/test.c -o $(LINKED_TEST_NAME)

test_linked_stack: $(LINKED_LIST_OBJS)
	@$(CC) $(TEST_CFLAGS) $(INC_PATH) $(LINKED_LIST_OBJS) test/main.c $(LINKED_TEST_FILES) -o $(LINKED_TEST_NAME)

test_array_stack: $(ARRAY_OBJS)
	@$(CC) $(TEST_CFLAGS) $(INC_PATH) $(ARRAY_OBJS) test/main.c $(ARRAY_TEST_FILES) -o $(ARRAY_TEST_NAME)

report: test_run_time_linked test_run_time_array
	@rm -f report
	@./$(ARRAY_TEST_NAME)
	@./$(LINKED_TEST_NAME)
	@$(CC) $(TEST_CFLAGS) test/report.c -o report && ./report

clean:
	@rm -f $(ARRAY_OBJS)
	@rm -f $(LINKED_LIST_OBJS)

re: fclean all

fclean: clean
	@rm -f $(ARRAY_TEST_NAME)
	@rm -f $(LINKED_TEST_NAME)
	@rm -f *.txt
	@rm -f report
	

.PHONY: all clean fclean re test report
