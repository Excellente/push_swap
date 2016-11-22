/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:56:30 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/22 11:22:37 by emsimang         ###   ########.fr       */
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

int		ft_can_rotate(t_stack *p)
{
	int		top;
	int		bottom;
	t_stack	*q;

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
		free(q->elements);
		free(q);
		if (top > bottom)
			return (1);
		else if (top == bottom)
			return (0);
		else if (top < bottom)
			return (-1);
	}
	return (12345);
}

int		ft_can_rrotate(t_stack *p)
{
	int		top;
	int		top2;
	int		bottom;
	t_stack	*q;

	if (p->size > 1)
	{
		q = ft_new_stack(p->max_elem);
		top = ft_pop(p);
		while (p->size > 2)
			ft_push(ft_pop(p), q);
		top2 = ft_pop(p);
		bottom = ft_top(p);
		ft_push(top2, p);
		while (!ft_isempty(q))
			ft_push(ft_pop(q), p);
		ft_push(top, p);
		free(q->elements);
		free(q);
		if (top > bottom && top2 > bottom && top < top2)
			return (1);
		return (0);
	}
	return (12345);
}
