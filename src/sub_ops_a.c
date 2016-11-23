/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_ops_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:09:56 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/21 17:54:12 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *p, char *op)
{
	int	tmp;
	int	dum;

	if (p->size > 1)
	{
		tmp = ft_pop(p);
		dum = ft_pop(p);
		ft_push(tmp, p);
		ft_push(dum, p);
	}
}

void	ft_rrotate(t_stack *a)
{
	int		tmp;
	t_stack	*b;

	if (a->size > 1)
	{
		b = ft_new_stack(a->max_elem);
		while (!ft_isempty(a))
			ft_push_in("pb", "ft_rrotate", a, b);
		tmp = ft_pop(b);
		while (!ft_isempty(b))
			ft_push_in("pa", "ft_rrotate", a, b);
		ft_push(tmp, a);
		free(b->elements);
		free(b);
	}
}

void	ft_rotate(t_stack *a)
{
	int		tmp;
	t_stack	*b;

	if (a->size > 1)
	{
		b = ft_new_stack(a->max_elem);
		tmp = ft_pop(a);
		while (!ft_isempty(a))
			ft_push_in("pb", "ft_rotate", a, b);
		ft_push(tmp, a);
		while (!ft_isempty(b))
			ft_push_in("pa", "ft_rotate", a, b);
		free(b->elements);
		free(b);
	}
}

void	ft_push(int elem, t_stack *p)
{
	if (p->size < p->max_elem)
	{
		p->elements[p->size] = elem;
		p->size += 1;
	}
	else
		ft_print_error("Error: stack is full.");
}
