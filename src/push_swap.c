/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:28:57 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 15:24:48 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	int		size;
	char	**elem;
	t_stack *p;


	if (ac == 2)
	{
		ft_validate_args(av[1]);
		elem = ft_strsplit(av[1], 32);
		size = ft_strslen(elem);
		if (size >= 1)
		{
			p = ft_new_stack(size);
			ft_init_stack(&p, av[1]);
			ft_sort(p);
			free(p->elements);
			free(p);
		}
	}
	i = 0;
	while (elem[i])
		free(elem[i++]);
	free(elem);
	return (0);
}
