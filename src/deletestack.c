/**
 * @file deletestack.c
 * @author Athul Thomas (thomasathul@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-07-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "stack.h"

error_t delete_stack(stack_t *stack_ptr)
{
    free(stack_ptr->st_arr);
    stack_ptr->st_arr = NULL;
    return SUCCESS;
}