/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:24:48 by wayden            #+#    #+#             */
/*   Updated: 2023/03/11 20:05:19 by wayden           ###   ########.fr       */
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

int nb_rev(int index, int top)
{
    if(index < top/2)
        return(index+1);
    else
        return(top - index);
    return(0);
}

void verify(t_stack *b)
{
    if(b->stack[b->top] < b->stack[b->top-1])
        swap(b);
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
    (error == 1 && ft_printf("Error malloc stack a\n") && (free(a->stack),1));
    (error == 2 && ft_printf("Error malloc stack b\n") && ((free(a->stack),1),free(b->stack),1));
    (error == 3 && ft_printf("Error Int Overflow in Atoi\n") && (free(a->stack),free(b->stack),1));
    (error == 4 && ft_printf("Error not only numerical arguments\n") && (free(a->stack),free(b->stack),1));
    (error == 5 && ft_printf("Error at least one number appears 2 time in the stack\n") && (free(a->stack),free(b->stack),1));
    (error == 6 && ft_printf("Stack a already sorted\n") && (free(a->stack),free(b->stack),1));
}