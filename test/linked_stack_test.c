#include "ctest.h"
#include "../src_linked_list/linked_stack.h"
#include <stdlib.h>
#include <limits.h>

//////////////////////////////////////////////
//                 push_test                //
//////////////////////////////////////////////

CTEST_DATA(push_test)
{
    t_linked_stack *stack;
};

CTEST_SETUP(push_test)
{
    data->stack = create_stack();
}

CTEST_TEARDOWN(push_test)
{
	destroy_stack(&(data->stack));
    ASSERT_EQUAL(0, size(data->stack));
    ASSERT_NULL(data->stack);
}

CTEST2(push_test, to_empty_stack)
{
	push(&data->stack, 7);
    ASSERT_EQUAL(7, data->stack->element);
    ASSERT_EQUAL(1, size(data->stack));
}

CTEST2(push_test, to_non_empty_stack)
{
	push(&data->stack, 8);
 	push(&data->stack, 7);

    ASSERT_EQUAL(7, data->stack->element);
    ASSERT_EQUAL(8, data->stack->next->element);
    ASSERT_EQUAL(2, size(data->stack));
}

// ////////////////////////////////////////////
// //             rotate_test                //
// ////////////////////////////////////////////

CTEST_DATA(rotate_test)
{
    t_linked_stack *stack;
};

CTEST_SETUP(rotate_test)
{
    data->stack = create_stack();
}

CTEST_TEARDOWN(rotate_test)
{
	destroy_stack(&(data->stack));
    ASSERT_EQUAL(0, size(data->stack));
    ASSERT_NULL(data->stack);
}

CTEST2(rotate_test, empty_stack)
{
    rotate(&data->stack);
    ASSERT_EQUAL(0, size(data->stack));
}

CTEST2(rotate_test, one_element_linked_stack)
{
	push(&data->stack, 8);
    rotate(&data->stack);
    ASSERT_EQUAL(1, size(data->stack));
    ASSERT_EQUAL(8, data->stack->element);
}

CTEST2(rotate_test, two_elements_stack)
{
	push(&data->stack, 1);
    push(&data->stack, 2);
    rotate(&data->stack);
    ASSERT_EQUAL(2, size(data->stack));
    ASSERT_EQUAL(1, data->stack->element);
    ASSERT_EQUAL(2, data->stack->next->element);
}

CTEST2(rotate_test, four_elements_stack)
{
	push(&data->stack, 3);
    push(&data->stack, 2);
    push(&data->stack, 1);
    push(&data->stack, 4);
      
    rotate(&data->stack);
    ASSERT_EQUAL(4, size(data->stack));
    
    t_linked_stack *cur = data->stack;
    ASSERT_EQUAL(1, cur->element);

    cur = cur->next;
    ASSERT_EQUAL(2, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(3, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(4, cur->element);
}

////////////////////////////////////////////
//           reverse_rotate_test          //
////////////////////////////////////////////

CTEST_DATA(reverse_rotate_test)
{
    t_linked_stack *stack;
};

CTEST_SETUP(reverse_rotate_test)
{
    data->stack = create_stack();
}

CTEST_TEARDOWN(reverse_rotate_test)
{
	destroy_stack(&(data->stack));
    ASSERT_EQUAL(0, size(data->stack));
    ASSERT_NULL(data->stack);
}

CTEST2(reverse_rotate_test, empty_stack)
{
    reverse_rotate(&data->stack);
    ASSERT_EQUAL(0, size(data->stack));
}

CTEST2(reverse_rotate_test, one_element_linked_stack)
{
	push(&data->stack, 8);
    reverse_rotate(&data->stack);
    ASSERT_EQUAL(1, size(data->stack));
    ASSERT_EQUAL(8, data->stack->element);
}

CTEST2(reverse_rotate_test, two_elements_stack)
{
	push(&data->stack, 1);
    push(&data->stack, 2);

    reverse_rotate(&data->stack);
    ASSERT_EQUAL(2, size(data->stack));
    ASSERT_EQUAL(1, data->stack->element);
    ASSERT_EQUAL(2, data->stack->next->element);

}

CTEST2(reverse_rotate_test, four_elements_stack)
{
	push(&data->stack, 1);
    push(&data->stack, 4);
    push(&data->stack, 3);
    push(&data->stack, 2);

    reverse_rotate(&data->stack);
    ASSERT_EQUAL(4, size(data->stack));
    
    t_linked_stack *cur = data->stack;
    ASSERT_EQUAL(1, cur->element);

    cur = cur->next;
    ASSERT_EQUAL(2, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(3, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(4, cur->element);
}

////////////////////////////////////////////
//              swap_test                 //
////////////////////////////////////////////

CTEST_DATA(swap_test)
{
    t_linked_stack *stack;
};

CTEST_SETUP(swap_test)
{
    data->stack = create_stack();
}

CTEST_TEARDOWN(swap_test)
{
	destroy_stack(&(data->stack));
    ASSERT_EQUAL(0, size(data->stack));
    ASSERT_NULL(data->stack);
}

CTEST2(swap_test, empty_stack)
{
    swap(&data->stack);
    ASSERT_EQUAL(0, size(data->stack));
}

CTEST2(swap_test, one_element_linked_stack)
{
    push(&data->stack, 1);
    swap(&data->stack);

    ASSERT_EQUAL(1, size(data->stack));
    ASSERT_EQUAL(1, data->stack->element);
}

CTEST2(swap_test, two_element_linked_stack)
{
    push(&data->stack, 2);
    push(&data->stack, 1);
    swap(&data->stack);

    ASSERT_EQUAL(2, size(data->stack));
    ASSERT_EQUAL(2, data->stack->element);
    ASSERT_EQUAL(1, data->stack->next->element);
}


CTEST2(swap_test, five_elements_stack)
{
    push(&data->stack, 2);
    push(&data->stack, 3);
    push(&data->stack, 4);
    push(&data->stack, 5);
    swap(&data->stack);

    ASSERT_EQUAL(4, size(data->stack));
    t_linked_stack *cur = data->stack;
    ASSERT_EQUAL(4, cur->element);

    cur = cur->next;
    ASSERT_EQUAL(5, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(3, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(2, cur->element);
}

////////////////////////////////////////////
//              destroy_test              //
////////////////////////////////////////////

CTEST(destroy_test, create_and_destroy)
{
    t_linked_stack *stack = create_stack();
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);
    push(&stack, 6);
	destroy_stack(&stack);
    ASSERT_EQUAL(0, size(stack));
    ASSERT_NULL(stack);
}


////////////////////////////////////////////
//             populate_test              //
////////////////////////////////////////////


CTEST_DATA(populate_test)
{
    t_linked_stack *stack;
};

CTEST_SETUP(populate_test)
{
    data->stack = create_stack();
}

CTEST_TEARDOWN(populate_test)
{
	destroy_stack(&(data->stack));
    ASSERT_EQUAL(0, size(data->stack));
    ASSERT_NULL(data->stack);
}

CTEST2(populate_test, five_elements_stack)
{
    const int elements[] = {1, 2, 3, 4, 5};
    populate_stack(&data->stack, elements, 5);
    ASSERT_EQUAL(5, size(data->stack));
    
    t_linked_stack *cur = data->stack;
    ASSERT_EQUAL(1, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(2, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(3, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(4, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(5, cur->element);
}



////////////////////////////////////////////
//             visit_test              //
////////////////////////////////////////////

int visit(int element)
{
    return (element + 1);
}

CTEST_DATA(visit_test)
{
    t_linked_stack *stack;
};

CTEST_SETUP(visit_test)
{
    data->stack = create_stack();
}

CTEST_TEARDOWN(visit_test)
{
	destroy_stack(&(data->stack));
    ASSERT_EQUAL(0, size(data->stack));
    ASSERT_NULL(data->stack);
}

CTEST2(visit_test, five_elements_stack)
{
    const int elements[] = {1, 2, 3, 4, 5};
    populate_stack(&data->stack, elements, 5);
    ASSERT_EQUAL(5, size(data->stack));

    visit_elements(data->stack, visit);

    t_linked_stack *cur = data->stack;
    ASSERT_EQUAL(2, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(3, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(4, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(5, cur->element);
    cur = cur->next;
    ASSERT_EQUAL(6, cur->element);
}
