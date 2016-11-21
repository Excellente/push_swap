/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:56:30 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/21 17:52:35 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_numcmp(t_stack *p)
{
	int top;

	if (p->size > 1)
	{
		top = ft_pop(p);
		if (top > ft_top(p))
		{
			ft_push(top, p);
			return (1);
		}
		else if (top == ft_top(p))
		{
			ft_push(top, p);
			return (0);
		}
		else
		{
			ft_push(top, p);
			return (-1);
		}
	}
	return (12345);
}

int	ft_can_rotate(t_stack *p)
{
	int	top;
	int	bottom;
	t_stack *q;

	if (p->size > 1)
	{
		q = ft_new_stack(p->max_elem);
		top = ft_pop(p);
		while (p->size > 1)
			ft_push(ft_pop(p), q);
		bottom = ft_top(p);
		while (!ft_isempty(q))
			ft_push(ft_pop(q), p);
		ft_push(top, p);
		if (top > bottom)
			return (1);
		else if (top == bottom)
			return (0);
		else if (top < bottom)
			return (-1);
	}
	free(q->elements);
	free(q);
	return (12345);
}
