/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:38:05 by emsimang          #+#    #+#             */
/*   Updated: 2016/09/05 13:39:44 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	int		i;
	int		tmp;
	int		size;
	char	**elem;
	t_stack	*p;

	i = 0;
	if (ac == 2)
	{
		ft_validate_args(av[1]);
		elem = ft_strsplit(av[1], ' ');
		size = ft_strslen(elem);
		p = ft_new_stack(size);
		ft_init_stack(&p, av[1]);
		//ft_print_stack(p, "p");
	}
	else
		ft_print_error("ERROR!\n");
	while (elem[i])
		free(elem[i++]);
	free(elem);
	free(p->elements);
	free(p);
	return (0);
}
