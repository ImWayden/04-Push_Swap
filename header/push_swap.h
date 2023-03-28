/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: therodri <therodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 04:08:41 by therodri          #+#    #+#             */
/*   Updated: 2023/03/28 04:08:41 by therodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/header/ft_printf.h"
# include "../Libft/header/libft.h"
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*stack;
	int		top;
	int		index;
	int		nb_rev;
	int		max;
	int		min;
	char	letter;
}	t_stack;

typedef struct s_moves
{
	int	nb_ra;
	int	nb_rb;
	int	nb_rra;
	int	nb_rrb;
	int	nb_rr;
	int	nb_rrr;
	int	ra_rb;
	int	rra_rrb;
	int	ra_rrb;
	int	rra_rb;
	int	mincost;
}	t_moves;

int		ft_min(int count, ...);
int		ft_abs(int n);
void	choose_rotate(t_stack *s, int nb_rev);
void	error_manager(t_stack *a, t_stack *b, int error);
void	push(t_stack *stackfrom, t_stack *stackto, int i);
void	swap(t_stack *stack, int i);
void	rotate(t_stack *stack, int rr);
void	rev_rotate(t_stack *s, int rrr);
int		nb_rev(int index, int top);
void	print_stacks(t_stack *a, t_stack *b);
void	basic_sort(t_stack *a, t_stack *b);
void	set_min_max(t_stack *b, long long int element);
void	apply_rotate(t_stack *a, t_stack *b, t_moves *moves);
void	short_sort(t_stack *a);
void	short_sort2(t_stack *a, t_stack *b);
void	init_stack(t_stack *a, t_stack *b, int size, int *error);
void	check_stack(t_stack *a, int *error);
int		atoi_error(char *str, int *error);

#endif