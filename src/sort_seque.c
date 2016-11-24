/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:15:46 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/23 17:59:15 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isrsorted(t_stack *a)
{
	int		ret;
	t_stack	*b;

	if (a->size > 0)
	{
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
	return (1);
}

int		ft_issorted(t_stack *a)
{
	int		ret;
	t_stack	*b;

	if (a->size > 0)
	{
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
	return(1);
}

int	ft_done(t_stack *a, t_stack *b)
{
	if (ft_issorted(a) == 1 && ft_isempty(b) == 1)
		return (1);
	return (0);
}

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
	if (ft_can_rotate(a) == 1 && ft_numcmp(a) != 1 && !ft_can_rrr(a, b))
		ft_rot_stack("ra", "ft_sort", a, b);
	if (ft_can_rotate(b) == -1)
		ft_rot_stack("rb", "ft_sort", a, b);
}

void	ft_swaping(t_stack *a, t_stack *b)
{
	if (ft_numcmp(a) == 1 && ft_numcmp(b) == -1)
		ft_swap_in("ss", "ft_sort", a, b);
	else if (ft_numcmp(a) == 1)
	{
		ft_swap_in("sa", "ft_sort", a, b);
		if (!ft_issorted(a) && ft_can_rrotate(a) != 1)
			ft_push_in("pb", "ft_sort", a, b);
	}
	if (ft_numcmp(b) == -1 && !ft_can_rrr(a, b))
		ft_swap_in("sb", "ft_sort", a, b);
	if (!ft_issorted(a) && ft_can_rrotate(a) != 1)
		ft_push_in("pb", "ft_sort", a, b);
}

int		ft_get_biggest(t_stack *a)
{
	int		tmp;
	t_stack	*b;

	if (a->size > 0)
	{
		tmp = ft_top(a);
		b = ft_new_stack(a->max_elem);
		while (!ft_isempty(a))
		{
			if (tmp < ft_top(a))
				tmp = ft_top(a);
			ft_push(ft_pop(a), b);
		}
		while (!ft_isempty(b))
			ft_push(ft_pop(b), a);
		free(b->elements);
		free(b);
		return (tmp);
	}
	return (INT_MIN);
}
int		ft_get_smallest(t_stack *a)
{
	int		tmp;
	t_stack	*b;

	if (a->size > 0)
	{
		tmp = ft_top(a);
		b = ft_new_stack(a->max_elem);
		while (!ft_isempty(a))
		{
			if (tmp > ft_top(a))
				tmp = ft_top(a);
			ft_push(ft_pop(a), b);
		}
		while (!ft_isempty(b))
			ft_push(ft_pop(b), a);
		free(b->elements);
		free(b);
		return (tmp);
	}
	return (INT_MAX);
}

void	ft_refill_a(t_stack *a, t_stack *b)
{
	if (ft_issorted(a) == 1 && ft_isrsorted(b) == 1)
	{
		if (ft_get_smallest(a) > ft_get_biggest(b))
			while (!ft_isempty(b))
				ft_push_in("pa", "ft_sort", a, b);
		else
			ft_push_in("pa", "ft_sort", a, b);
	}
	else if ((ft_issorted(a) == 1 && !(ft_isrsorted(b) == 1)))
		ft_push_in("pa", "ft_sort", a, b);
	if (ft_isempty(a))
		while (!ft_isempty(b))
			ft_push_in("pa", "ft_sort", a, b);
}

void	ft_sort(t_stack *a)
{
	t_stack	*b;

	b = ft_new_stack(a->max_elem);
	ft_strcpy(b->name, "tmp");
	while (!ft_done(a, b))
	{
		ft_refill_a(a, b);
		ft_swaping(a, b);
		ft_rotation(a, b);
	}
	free(b->elements);
	free(b);
}
