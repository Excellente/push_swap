/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 12:40:40 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 12:41:03 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min(t_stack *a)
{
	int		tmp;
	int		min_index;
	t_stack	*b;

	if (a->size > 1)
	{
		tmp = ft_top(a);
		b = ft_new_stack(a->max_elem);
		while (!ft_isempty(a))
		{
			if (ft_top(a) < tmp)
			{
				min_index = a->size - 1;
				tmp = ft_top(a);
			}
			ft_push(ft_pop(a), b);
		}
		while (!ft_isempty(b))
			ft_push(ft_pop(b), a);
		free(b->elements);
		free(b);
		return (min_index);
	}
	return (INT_MAX);
}

int	ft_get_max(t_stack *a)
{
	int		tmp;
	int		max_index;
	t_stack	*b;

	if (a->size > 1)
	{
		tmp = ft_top(a);
		b = ft_new_stack(a->max_elem);
		while (!ft_isempty(a))
		{
			if (ft_top(a) > tmp)
			{
				max_index = a->size - 1;
				tmp = ft_top(a);
			}
			ft_push(ft_pop(a), b);
		}
		while (!ft_isempty(b))
			ft_push(ft_pop(b), a);
		free(b->elements);
		free(b);
		return (max_index);
	}
	return (INT_MIN);
}
