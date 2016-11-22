/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:28:57 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/22 12:13:16 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	int		num;
	int		size;
	char	**elem;
	t_stack *p;

	if (ac == 2)
	{
		i = 0;
		ft_validate_args(av[1]);
		elem = ft_strsplit(av[1], 32);
		size = ft_strslen(elem);
		if (size > 1)
		{
			p = ft_new_stack(size);
			ft_init_stack(&p, av[1]);
			//ft_print_stack(p, "a");
			ft_sort(p);
			if (ft_issorted(p) == 1)
				ft_putstr("OK\n");
			else
				ft_putstr("KO\n");
			//ft_print_stack(p, "a");
			free(p->elements);
			free(p);
		}
		else if (size == 1)
			ft_putstr("OK\n");
	}
	else
		ft_print_error("ERROR\n");
	i = 0;
	while (elem[i])
		free(elem[i++]);
	free(elem);
	return (0);
}
