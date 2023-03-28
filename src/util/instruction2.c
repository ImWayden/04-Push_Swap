/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:43:04 by wayden            #+#    #+#             */
/*   Updated: 2023/03/28 00:07:28 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

void	do_rr(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->nb_rr > 0)
	{
		rotate(a, 1);
		rotate(b, 1);
		ft_printf("rr\n");
		moves->nb_rr--;
	}
	while (moves->ra_rb > 0)
	{
		if (moves->nb_ra > moves->nb_rb)
			rotate(a, 0);
		else if (moves->nb_ra < moves->nb_rb)
			rotate(b, 0);
		moves->ra_rb--;
	}
}

void	do_rrr(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->nb_rrr > 0)
	{
		rev_rotate(a, 1);
		rev_rotate(b, 1);
		ft_printf("rrr\n");
		moves->nb_rrr--;
	}
	while (moves->rra_rrb > 0)
	{
		if (moves->nb_rra > moves->nb_rrb)
			rev_rotate(a, 0);
		else if (moves->nb_rra < moves->nb_rrb)
			rev_rotate(b, 0);
		moves->rra_rrb--;
	}
}

void	do_ra_rrb(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->nb_ra > 0)
	{
		rotate(a, 0);
		moves->nb_ra--;
	}
	while (moves->nb_rrb > 0)
	{
		rev_rotate(b, 0);
		moves->nb_rrb--;
	}
}

void	do_rra_rb(t_stack *a, t_stack *b, t_moves *moves)
{
	while (moves->nb_rra > 0)
	{
		rev_rotate(a, 0);
		moves->nb_rra--;
	}
	while (moves->nb_rb > 0)
	{
		rotate(b, 0);
		moves->nb_rb--;
	}
}

void	apply_rotate(t_stack *a, t_stack *b, t_moves *moves)
{
	if (moves->mincost == moves->ra_rb + moves->nb_rr)
		do_rr(a, b, moves);
	else if (moves->mincost == moves->rra_rrb + moves->nb_rrr)
		do_rrr(a, b, moves);
	else if (moves->mincost == moves->ra_rrb)
		do_ra_rrb(a, b, moves);
	else if (moves->mincost == moves->rra_rb)
		do_rra_rb(a, b, moves);
}
