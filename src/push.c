/**
 * @file push.c
 * @author Athul Thomas (thomasathul@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"

error_t push(stack_t *stack_ptr, int item)
{
    stack_ptr->top++;
    stack_ptr->st_arr[stack_ptr->top] = item;
    return SUCCESS;
}