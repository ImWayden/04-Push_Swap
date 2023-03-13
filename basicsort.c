/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wayden <wayden@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:19:16 by wayden            #+#    #+#             */
/*   Updated: 2023/03/13 15:29:31 by wayden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int where_to(int a, t_stack *b)
{
    int i;
    int index;

    i = 0;
    index = i;
    if(a < b->min || a > b->max)
    {
        while(b->stack[i] < b->max)
            i++;
        return (i);
    }
    else
        while(i++ < b->top)
            if((i == b->top && a > b->stack[i] && a < b->stack[0]) 
                || (i != b->top && a > b->stack[i] && a < b->stack[i + 1]))
                    index = i;            

    return(index);
}

static t_moves get_instructions(t_stack *a, t_stack *b, int index_a, int index_b) 
{
    t_moves move;
    move.nb_ra = a->top - index_a;
    move.nb_rb = b->top - index_b;
    move.nb_rra = index_a + 1;
    move.nb_rrb = index_b + 1;
    move.nb_rr = ft_min(2,move.nb_ra,move.nb_rb);
    move.nb_rrr = ft_min(2, move.nb_rra,move.nb_rrb);
    move.ra_rb = -ft_min(2,-move.nb_ra, -move.nb_rb) - move.nb_rr;
    move.rra_rrb = -ft_min(2,-move.nb_rra, -move.nb_rrb) - move.nb_rrr;
    move.ra_rrb = move.nb_ra + move.nb_rrb;
    move.rra_rb = move.nb_rra + move.nb_rb;
    move.mincost = ft_min(4,move.ra_rb+move.nb_rr
        ,move.rra_rrb+move.nb_rrr,move.ra_rrb,move.rra_rb);
    return move;
}

static void find_index(t_stack *a, t_stack *b,t_moves *moves)
{
    int i;
    t_moves actual;
    
    moves->mincost = a->top + b->top;
    i = a->top + 1;
    while(--i >= 0)
    {
        actual = get_instructions(a,b,i,where_to(a->stack[i],b));
        if(actual.mincost < moves->mincost)
           *moves = actual;
    }    
}

static void order_b(t_stack *b)
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
    choose_rotate(b,nb_rev(b->index, b->top));
    i = -1;
}

void basic_sort(t_stack *a,t_stack *b)
{
    t_moves moves;
    push(a,b);
    push(a,b);
    set_min_max(b,2147483648);
    while(a->top >= 0)
    {
        find_index(a,b,&moves);
        apply_rotate(a,b,&moves);
        push(a,b);
        set_min_max(b,b->stack[b->top]);
    }
    order_b(b);
    while(b->top >= 0)
        push(b,a);
}
