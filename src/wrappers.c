/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:32:28 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 12:30:50 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotation(t_stack *a, t_stack *b)
{
	if (ft_can_rrr(a, b))
		ft_rot_stack("rrr", "ft_sort", a, b);
	if (ft_can_rr(a, b))
		ft_rot_stack("rr", "ft_sort", a, b);
	if (ft_can_rrotate(b) == -1)
		ft_rot_stack("rrb", "ft_sort", a, b);
	if (ft_can_rrotate(a) == 1 && !ft_can_rrr(a, b) && ft_numcmp(a) != 1)
		ft_rot_stack("rra", "ft_sort", a, b);
	if (ft_can_rotate(a) == 1 && !ft_can_rrr(a, b))
		ft_rot_stack("ra", "ft_sort", a, b);
	if (ft_can_rotate(b) == -1)
		ft_rot_stack("rb", "ft_sort", a, b);
}

void	ft_swaping(t_stack *a, t_stack *b)
{
	if (ft_numcmp(a) == 1 && ft_numcmp(b) == -1)
		ft_swap_in("ss", "ft_sort", a, b);
	else if (ft_numcmp(a) == 1 && ft_can_rotate(a) != 1)
	{
		ft_swap_in("sa", "ft_sort", a, b);
		if (!ft_issorted(a) && ft_can_rrotate(a) != 1)
			ft_push_in("pb", "ft_sort", a, b);
	}
	if (ft_numcmp(b) == -1 && !ft_can_rrr(a, b))
		ft_swap_in("sb", "ft_sort", a, b);
	if (!ft_issorted(a) && ft_can_rrotate(a) != 1 && ft_numcmp(a) != 1)
		ft_push_in("pb", "ft_sort", a, b);
}

void	ft_refill_a(t_stack *a, t_stack *b)
{
	if (ft_issorted(a) == 1 && ft_isrsorted(b) == 1)
	{
		if (ft_top(a) > ft_top(b))
			while (!ft_isempty(b))
				ft_push_in("pa", "ft_sort", a, b);
		else
			ft_push_in("pa", "ft_sort", a, b);
	}
	else if ((ft_issorted(a) == 1 && !(ft_isrsorted(b) == 1)))
		ft_push_in("pa", "ft_sort", a, b);
	if (ft_isempty(a))
		ft_push_in("pa", "ft_sort", a, b);
}
