/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:47:03 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 10:47:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <limits.h>
# include "push_swap.h"
# include "Libft/header/libft.h"
# include "Libft/header/ft_printf.h"
# include <ctype.h>

typedef struct s_stack
{
    int *stack;
    int top;
    int index;
    int nb_rev;
    char letter;
}   t_stack;

int ft_abs(int n);
void verify(t_stack *b);
void error_manager(t_stack *a, t_stack *b, int error);
void push(t_stack *stackfrom, t_stack *stackto);
void swap(t_stack *stack);
void rotate(t_stack *stack,int rr);
void rev_rotate(t_stack *s,int rrr);
void order_b(t_stack *b);
int nb_rev(int index, int top);
void launch_sort(t_stack *a,t_stack *b);
void print_stacks(t_stack *a, t_stack *b);

#endif