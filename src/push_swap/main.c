/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:06:01 by therodri          #+#    #+#             */
/*   Updated: 2023/03/28 04:06:01 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"

static void	launch_sort(t_stack *a, t_stack *b)
{
	if (a->top == 2)
		short_sort(a);
	else if (a->top < 11)
		short_sort2(a, b);
	else
		basic_sort(a, b);
}

int	main(int argc, char **argv)
{
	int		i;
	int		error;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	error = 0;
	i = -1;
	init_stack(&a, &b, argc - 1, &error);
	if (error > 0)
		return (error_manager(&a, &b, error), 0);
	while (++i < argc - 1)
		a.stack[i] = atoi_error(argv[argc - 1 - i], &error);
	check_stack(&a, &error);
	if (error > 0)
		return (error_manager(&a, &b, error), 0);
	launch_sort(&a, &b);
	return (free(a.stack), free(b.stack), 0);
}
