/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:12:16 by wayden            #+#    #+#             */
/*   Updated: 2023/03/28 00:23:41 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static int	find_min(t_stack *a)
{
	int	min_value;
	int	i;
	int	min_index;

	min_value = a->stack[a->top];
	i = a->top;
	min_index = i;
	while (i >= 0)
	{
		if (a->stack[i] < min_value)
		{
			min_value = a->stack[i];
			min_index = i;
		}
		i--;
	}
	return (min_index);
}

void	short_sort(t_stack *a)
{
	int	min;
	int	max;

	min = ft_min(3, a->stack[0], a->stack[1], a->stack[2]);
	max = -ft_min(3, -a->stack[0], -a->stack[1], -a->stack[2]);
	if (max == a->stack[0] && min != a->stack[2])
		swap(a, 0);
	else if (min == a->stack[2] && max != a->stack[0])
	{
		swap(a, 0);
		rotate(a, 0);
	}
	else if (min == a->stack[0] && max == a->stack[2])
	{
		swap(a, 0);
		rev_rotate(a, 0);
	}
	else if (min == a->stack[1])
		rotate(a, 0);
	else if (min == a->stack[0] && max == a->stack[1])
		rev_rotate(a, 0);
}

void	short_sort2(t_stack *a, t_stack *b)
{
	while (a->top > 2)
	{
		a->index = find_min(a);
		choose_rotate(a, nb_rev(a->index, a->top));
		push(a, b, 0);
	}
	short_sort(a);
	while (b->top > -1)
		push(b, a, 0);
}
