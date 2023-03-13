/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:24:48 by wayden            #+#    #+#             */
/*   Updated: 2023/03/13 13:14:21 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_abs(int n)
{
    if (n < 0) 
        return (-n);
    else 
        return (n);
    return (0);
}

void set_min_max(t_stack *b,long long int element)
{
    if(element == 2147483648 && b->stack[0] > b->stack[1])
    {
        b->min = b->stack[1];
        b->max = b->stack[0];
    }
    else if (element == 2147483648 && b->stack[0] < b->stack[1])
    {
        b->min = b->stack[0];
        b->max = b->stack[1];
    }    
    else if(element < b->min)
        b->min = (int)element;
    else if(element > b->max)
        b->max = (int)element;
}

int ft_min(int count, ...) {
    va_list args;
    va_start(args, count);

    int min_val = va_arg(args, int);
    int i = 1;
    while (i < count) 
    {
        int val = va_arg(args, int);
        if (val < min_val) {
            min_val = val;
        }
        i++;
    }
    va_end(args);
    return min_val;
}

int nb_rev(int index, int top)
{
    if(index < top/2)
        return(index+1);
    else
        return(top - index);
    return(0);
}

void print_stacks(t_stack *a, t_stack *b)
{
    int i = b->top + a->top + 2;
    while(--i >= 0)
        ft_printf("[%d] %d  %d\n", i, a->stack[i],b->stack[i]);
    ft_printf("\n");
}

void error_manager(t_stack *a, t_stack *b, int error)
{
    (error == 1 && ft_printf("Error malloc stack a\n") 
    && (free(a->stack),1));
    (error == 2 && ft_printf("Error malloc stack b\n") 
    && ((free(a->stack),1),free(b->stack),1));
    (error == 3 && ft_printf("Error Int Overflow in Atoi\n") 
    && (free(a->stack),free(b->stack),1));
    (error == 4 && ft_printf("Error not only numerical arguments\n") 
    && (free(a->stack),free(b->stack),1));
    (error == 5 && ft_printf("Error duplicate number\n") 
    && (free(a->stack),free(b->stack),1));
    (error == 6 && ft_printf("Stack a already sorted\n") 
    && (free(a->stack),free(b->stack),1));
}