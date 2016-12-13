/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:28:57 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 12:56:44 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **elem)
{
	int i;

	i = 0;
	while (elem[i])
		free(elem[i++]);
	free(elem);
}

void	ft_init(int ac, char **av, int *size, char ***elem)
{
	ft_validate_args(ac, av);
	if (ac > 2)
		*size = ac - 1;
	else
	{
		*elem = ft_strsplit(av[1], 32);
		*size = ft_strslen(*elem);
	}
}

int		main(int ac, char **av)
{
	int		i;
	int		size;
	char	**elem;
	t_stack *p;

	if (ac >= 2)
	{
		ft_init(ac, av, &size, &elem);
		if (size >= 1)
		{
			p = ft_new_stack(size);
			ft_init_stack(&p, ac, av);
			ft_sort(p);
			free(p->elements);
			free(p);
		}
	}
	if (ac == 2)
		ft_free(elem);
	return (0);
}
