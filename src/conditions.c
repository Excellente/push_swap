/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:56:30 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/23 18:04:09 by emsimang         ###   ########.fr       */
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

int		ft_can_rotate_a(t_stack *p)
{
	int		top;
	int		bottom;
	t_stack	*q;

	if (p->size > 1)
	{
		q = ft_new_stack(p->max_elem);
		ft_strcpy(q->name, "q_tmp");
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

int		ft_can_rotate_b(t_stack *p)
{
	int		top;
	int		bottom;
	t_stack	*q;

	if (p->size > 1)
	{
		top = ft_top(p);
		q = ft_new_stack(p->max_elem);
		while (!ft_isempty(p))
			ft_push(ft_pop(p), q);
		bottom = ft_top(q);
		while (!ft_isempty(q))
			ft_push(ft_pop(q), p);
		free(q->elements);
		free(q);
		if (top < bottom)
			return (1);
		else if (top == bottom)
			return (0);
		else
			return (-1);
	}
	return (12345);
}

int		ft_can_rrotate_b(t_stack *p)
{
	int		top;
	int		top2;
	int		bottom;
	t_stack	*q;

	if (p->size > 1)
	{
		q = ft_new_stack(p->max_elem);
		top = ft_top(p);
		while (p->size > 2)
			ft_push(ft_pop(p), q);
		top2 = ft_pop(p);
		bottom = ft_top(p);
		ft_push(top2, p);
		while (!ft_isempty(q))
			ft_push(ft_pop(q), p);
		free(q->elements);
		free(q);
		if (top < bottom && top2 < bottom)
			return (1);
		return (0);
	}
	return (12345);
}

int		ft_can_rrotate_a(t_stack *p)
{
	int		top;
	int		top2;
	int		bottom;
	t_stack	*q;

	if (p->size > 1)
	{
		q = ft_new_stack(p->max_elem);
		top = ft_top(p);
		while (p->size > 2)
			ft_push(ft_pop(p), q);
		top2 = ft_pop(p);
		bottom = ft_top(p);
		ft_push(top2, p);
		while (!ft_isempty(q))
			ft_push(ft_pop(q), p);
		free(q->elements);
		free(q);
		if (top > bottom && top2 > bottom)
			return (1);
		return (0);
	}
	return (12345);
}
