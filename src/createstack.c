/**
 * @file createstack.c
 * @author Athul Thomas (thomasathul@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"

error_t create_stack(stack_t *stack_ptr, size_t stack_size)
{
    if (NULL == stack_ptr)
        return NULL_PTR;

    stack_ptr->st_arr = malloc(sizeof(user_data_t) * stack_size);

    if (NULL == stack_ptr->st_arr)
        return NULL_PTR;

    stack_ptr->top = -1;

    return SUCCESS;
}