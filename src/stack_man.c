/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_man.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:21:13 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/22 08:56:54 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_isempty(t_stack *p)
{
	if (p->size == 0)
		return (1);
	return (0);
}

int		ft_top(t_stack *p)
{
	int top;

	top = p->size - 1;
	if (p->size > 0)
		return (p->elements[top]);
	else
		ft_print_error("Error: stack is empty.\n");
	return (ERROR - 48);
}

int		ft_pop(t_stack *p)
{
	int		val;
	int		index;

	if (p->size > 0)
	{
		index = p->size;
		index -= 1;
		val = p->elements[index];
		p->elements[index] = '\0';
		p->size--;
	}
	else
	{
		val = '\0';
		ft_print_error("Error: stack is empty.\n");
	}
	return (val);
}

void	ft_print_stack(t_stack *p, char *n)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	j = p->size - 1;
	tmp = p->elements;
	while (i < p->size)
	{
		printf("%d\n", tmp[j]);
		i++;
		j--;
	}
	printf("-\n");
	printf("%s\n", n);
}

t_stack	*ft_new_stack(int max_elem)
{
	t_stack	*p;

	p = (t_stack *)malloc(sizeof(*p));
	p->size = 0;
	p->max_elem = max_elem;
	p->elements = (int *)malloc(sizeof(int) * max_elem);
	return (p);
}
