/**
 * @file stack.h
 * @author Athul Thomas (thomasathul@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __STACK_H_
#define __STACK_H_

#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"

// Update this variable if different data needs to be stored in stack
typedef int user_data_t;

typedef enum error_t
{
    SUCCESS,
    NULL_PTR,
    STACK_EMPTY
} error_t;

typedef struct stack_t
{
    user_data_t *st_arr;
    int top;
} stack_t;

/**
 * @brief Create a stack object
 * 
 * @param stack_ptr 
 * @param stack_size 
 * @return error_t 
 */

error_t create_stack(stack_t *stack_ptr, size_t stack_size);

/**
 * @brief Delete a stack object
 * 
 * @param stack_ptr 
 * @return error_t 
 */

error_t delete_stack(stack_t *stack_ptr);

/**
 * @brief Push element into stack
 * 
 * @param stack_ptr 
 * @param item 
 * @return error_t 
 */

error_t push(stack_t *stack_ptr, int item);

/**
 * @brief Pop an element
 * 
 * @param stack_ptr 
 * @return error_t 
 */

error_t pop(stack_t *stack_ptr);

/**
 * @brief Peek a stack object
 * 
 * @param stack_ptr 
 * @return error_t 
 */

error_t peek(stack_t *stack_ptr);

#endif // __STACK_H_