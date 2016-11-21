/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:12:18 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/21 16:04:48 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putop(char *op_name)
{
	write(1, op_name, ft_strlen(op_name));
	write(1, "\n", 1);
}

void	ft_push_in(char *op_name, char *caller, t_stack *a, t_stack *b)
{
	int tmp;

	if (ft_strcmp(op_name, "pa") == 0)
	{
		tmp = ft_pop(b);
		ft_push(tmp, a);
	}
	else if (ft_strcmp(op_name, "pb") == 0)
	{
		tmp = ft_pop(a);
		ft_push(tmp, b);
	}
	if (ft_strcmp(caller, "ft_sort") == 0)
		ft_putop(op_name);
}

void	ft_rot_stack(char *op_name, char *caller, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op_name, "ra") == 0)
		ft_rotate(a);
	else if (ft_strcmp(op_name, "rb") == 0)
		ft_rotate(b);
	else if (ft_strcmp(op_name, "rra") == 0)
		ft_rrotate(a);
	else if (ft_strcmp(op_name, "rrb") == 0)
		ft_rrotate(b);
	else if (ft_strcmp(op_name, "rr") == 0)
	{
		ft_rotate(a);
		ft_rotate(b);
	}
	else if (ft_strcmp(op_name, "rrr") == 0)
	{
		ft_rrotate(a);
		ft_rrotate(b);
	}
	if (ft_strcmp(caller, "ft_sort") == 0)
		ft_putop(op_name);
}

void	ft_swap_in(char *op_name, char * caller, t_stack *a, t_stack *b)
{
	if (ft_strcmp(op_name, "sa") == 0)
		ft_swap(a, op_name);
	else if (ft_strcmp(op_name, "sb") == 0)
		ft_swap(b, op_name);
	else if (ft_strcmp(op_name, "ss") == 0)
	{
		ft_swap(a, "");
		ft_swap(b, "");
	}
	if (ft_strcmp(caller, "ft_sort") == 0)
		ft_putop(op_name);
}