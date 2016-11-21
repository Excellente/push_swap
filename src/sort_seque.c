/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:15:46 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/21 18:10:00 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isrsorted(t_stack *a)
{
	int		ret;
	t_stack	*b;

	b = ft_new_stack(a->max_elem);
	ft_push(ft_pop(a), b);
	while (!ft_isempty(a) && (ft_top(a) < ft_top(b)))
		ft_push(ft_pop(a), b);
	ret = a->size;
	while (!ft_isempty(b))
		ft_push(ft_pop(b), a);
	free(b->elements);
	free(b);
	if (ret == 0)
		return (1);
	else
		return (0);
}

int		ft_issorted(t_stack *a)
{
	int		ret;
	t_stack	*b;

	b = ft_new_stack(a->max_elem);
	ft_push(ft_pop(a), b);
	while (!ft_isempty(a) && (ft_top(a) > ft_top(b)))
		ft_push(ft_pop(a), b);
	ret = a->size;
	while (!ft_isempty(b))
		ft_push(ft_pop(b), a);
	free(b->elements);
	free(b);
	if (ret == 0)
		return (1);
	else
		return (0);
}

void	ft_sort(t_stack *a)
{
	t_stack	*b;

	b = ft_new_stack(a->max_elem);
	while (1)
	{
		if (ft_can_rotate(a) == 1)
			ft_rot_stack("ra", "ft_sort", a, b);
		if (ft_issorted(a) == 1 && ft_isrsorted(b) == 1)
			ft_push_in("pa", "ft_sort", a, b);
		if (ft_issorted(a) == 1 && ft_isempty(b) == 1)
			break ;
		if (ft_numcmp(a) == 1)
		{
			ft_swap_in("sa", "ft_sort", a, b);
			if (ft_issorted(a) == 1 && ft_isempty(b) == 1)
				break ;
			if (!ft_issorted(a))
			ft_push_in("pb", "ft_sort", a, b);
		}
		else if (!ft_issorted(a))
			ft_push_in("pb", "ft_sort", a, b);
		while (!ft_isempty(b) && ft_numcmp(b) == -1)
		{
			ft_swap_in("sb", "ft_sort", a, b);
			ft_push_in("pa", "ft_sort", a, b);
		}
		if (ft_isempty(a))
			while (!ft_isempty(b))
				ft_push_in("pa", "ft_sort", a, b);
		if (ft_issorted(a) == 1 && ft_isempty(b) == 1)
			break ;
	}
	free(b->elements);
	free(b);
}
