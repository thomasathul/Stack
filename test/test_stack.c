#include "unity.h"
#include "stack.h"
/* Required by the unity test framework */
void setUp() {}
/* Required by the unity test framework */
void tearDown() {}

/*Unit test for creating stack*/
void test_create_stack(void)
{
    stack_t my_stack;

    TEST_ASSERT_EQUAL(NULL_PTR, create_stack(NULL, 10));

    TEST_ASSERT_EQUAL(SUCCESS, create_stack(&my_stack, 10));

    stack_t *my_stack1 = malloc(sizeof(stack_t));
    TEST_ASSERT_EQUAL(SUCCESS, create_stack(my_stack1, 10));

    free(my_stack1);
}

/*Unit test for deleting stack*/

void test_delete_stack(void)
{
    stack_t my_stack;
    create_stack(&my_stack, 10);
    TEST_ASSERT_EQUAL(SUCCESS, delete_stack(&my_stack));
    stack_t *my_stack1 = malloc(sizeof(stack_t));
    create_stack(my_stack1, 10);
    TEST_ASSERT_EQUAL(SUCCESS, delete_stack(my_stack1));

    free(my_stack1);
}

/*Unit test for pushing element in stack*/

void test_push(void)
{
    stack_t my_stack;
    create_stack(&my_stack, 10);
    TEST_ASSERT_EQUAL(SUCCESS, push(&my_stack, 5));
    stack_t *my_stack1 = malloc(sizeof(stack_t));
    create_stack(my_stack1, 10);
    TEST_ASSERT_EQUAL(SUCCESS, push(my_stack1, 5));
    free(my_stack1);
}

/*Unit test for popping an element*/

void test_pop(void)
{
    stack_t my_stack;
    create_stack(&my_stack, 10);
    push(&my_stack, 5);
    TEST_ASSERT_EQUAL(SUCCESS, pop(&my_stack));
    stack_t *my_stack1 = malloc(sizeof(stack_t));
    create_stack(my_stack1, 10);
    TEST_ASSERT_EQUAL(STACK_EMPTY, pop(my_stack1));
    free(my_stack1);
    TEST_ASSERT_EQUAL(NULL_PTR, pop(NULL));
}

/*Unit test for peeking the top element*/

void test_peek(void)
{
    stack_t my_stack;
    create_stack(&my_stack, 10);
    push(&my_stack, 5);
    TEST_ASSERT_EQUAL(5, peek(&my_stack));
    stack_t *my_stack1 = malloc(sizeof(stack_t));
    create_stack(my_stack1, 10);
    push(&my_stack, 5);
    push(&my_stack, 7);
    TEST_ASSERT_EQUAL(7, peek(&my_stack));
    free(my_stack1);
    TEST_ASSERT_EQUAL(NULL_PTR, peek(NULL));
}
int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_create_stack);
    RUN_TEST(test_delete_stack);
    RUN_TEST(test_push);
    RUN_TEST(test_pop);
    RUN_TEST(test_peek);

    /* Close the Unity Test Framework */
    return UNITY_END();
}
