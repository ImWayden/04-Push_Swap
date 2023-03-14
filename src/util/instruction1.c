/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:27:48 by marvin            #+#    #+#             */
/*   Updated: 2023/02/28 09:27:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void push(t_stack *from, t_stack *to,int i)
{
    to->stack[to->top+1] = from->stack[from->top];
    from->stack[from->top] = 0;
    from->top--;
    to->top++;
    if(i == 0)
    {
        ft_printf("p%c",to->letter);
        ft_printf("\n");
    }
}

void swap(t_stack *s,int i)
{
    int temp;
    temp = s->stack[s->top];
    s->stack[s->top] = s->stack[s->top - 1];
    s->stack[s->top - 1] = temp;
    if(i == 0)
    {
        ft_printf("s%c",s->letter);
        ft_printf("\n");
    }  
}

void rotate(t_stack *s,int rr)
{
    int temp;
    int i;
    
    i = 0;
    temp = s->stack[s->top];
    while(i < s->top)
    {
        s->stack[s->top - i] = s->stack[s->top - i - 1];
        i++;
    }
    s->stack[0] = temp;
    if(rr == 0)
    {
        ft_printf("r%c",s->letter);
        ft_printf("\n");
    }
}

void rev_rotate(t_stack *s,int rrr)
{
    int temp;
    int i;
    
    i = 0;
    temp = s->stack[0];
    while(i < s->top)
    {
        s->stack[i] = s->stack[i + 1];
        i++;
    }
    s->stack[s->top] = temp;
    if(rrr == 0)
    {
        ft_printf("rr%c",s->letter);
        ft_printf("\n");
    }
}

void choose_rotate(t_stack *s, int nb_rev)
{
    int i;
    i = 0;
    while(i < nb_rev)
    {
        if(s->index >= nb_rev)
            rotate(s,0);
        else
            rev_rotate(s,0);
        i++;  
    }
}
