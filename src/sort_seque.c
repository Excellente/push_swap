/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:15:46 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 14:31:12 by emsimang         ###   ########.fr       */
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
