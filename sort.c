/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:12:16 by wayden            #+#    #+#             */
/*   Updated: 2023/03/11 20:04:41 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void choose_rotate(t_stack *s, int nb_rev, int i);

static int where_to(int element, t_stack *b)
{
    int min;
    int i;
    int actual;
    int index_and_nb_rev[2];

    i = 0;
    index_and_nb_rev[0] = i;
    min = abs(element - b->stack[0]);
    index_and_nb_rev[1] = nb_rev(i,b->top);
    while(i++ < b->top)
    {
        actual = ft_abs(element - b->stack[i]);
        if(actual < min || (actual == min && nb_rev(i, b->top) < index_and_nb_rev[1]))
        {
            min = actual;
            index_and_nb_rev[0] = i;
            index_and_nb_rev[1] = nb_rev(i,b->top);           
        }       
    }
    return(index_and_nb_rev[0]);
}

void order_b(t_stack *b)
{
    int i;
    int max;

    i = 0;
    b->index = 0;
    max = b->stack[i];
    while(i <= b->top)
    {
        if(b->stack[i] > max)
        {
            max = b->stack[i];
            b->index = i;
        }
        i++;
    }
    i = -1;
    choose_rotate(b,nb_rev(b->index, b->top),0);
}

static void find_index(t_stack *a, t_stack *b)
{
    int index_where_to_b; 
    int i;
    int nb_rev_tot;
    int nb_rev_min;
    
    nb_rev_min = a->top + b->top;
    i = a->top;
    while(i >= 0)
    {
        index_where_to_b = where_to(a->stack[i],b);
        nb_rev_tot = nb_rev(i, a->top) + nb_rev(index_where_to_b, b->top); 
        if( nb_rev_tot < nb_rev_min)
        {
            nb_rev_min = nb_rev_tot;
            b->index = index_where_to_b;
            a->index = i;
        }
        i--;
    }    
}

void choose_rotate_all(t_stack *a, t_stack *b, int nb_rev_a, int nb_rev_b)
{
    int i;
    
    i = 0;
    if(a->index >= nb_rev_a && b->index >= nb_rev_b)
        while(i < nb_rev_a && i < nb_rev_b)
        {
            rotate(a,1);
            rotate(b,1);
            ft_printf("rr\n");
            i++; 
        }    
    else if(a->index == nb_rev_a - 1 && b->index == nb_rev_b - 1)
        while(i < nb_rev_a && i < nb_rev_b)
        {
            rev_rotate(a, 1);
            rev_rotate(b, 1);
            ft_printf("rrr\n");
            i++;
        }
    choose_rotate(a,nb_rev_a,i);
    choose_rotate(b,nb_rev_b,i);        
}

void normal_sort(t_stack *a,t_stack *b)
{
    push(a,b);
    push(a,b);
    while(a->top >= 0)
    {
        find_index(a,b);
        choose_rotate_all(a,b,nb_rev(a->index, a->top),nb_rev(b->index, b->top));
        push(a,b);
        verify(b);
    }
    order_b(b);
    while(b->top >= 0)
        push(b,a);
    
}

void launch_sort(t_stack *a,t_stack *b)
{
    /*
    if(a->top < 3)
        short_sort(a,b);
    else if(a->top == 3)
        short_sort2(a,b);
    else if(a->top <= 10)
        short_sort3(a,b);
    else*/
    normal_sort(a,b);
}
/*
si l'index de l'élement de stack a est supérieur a a.top/2 alors le nombre de rev needed est de a.top - index de l'élément sinon il est égal a l'index de l'élement +1 
*/