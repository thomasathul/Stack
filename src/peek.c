/**
 * @file peek.c
 * @author Athul Thomas (thomasathul@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"

error_t peek(stack_t *stack_ptr)
{
    if (NULL == stack_ptr)
        return NULL_PTR;
    return stack_ptr->st_arr[stack_ptr->top];
}