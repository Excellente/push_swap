/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:34:05 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/09 15:58:04 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_stack **p, int ac, char **av)
{
	int		i;
	int		num;
	char	**elem;

	i = 0;
	if (ac == 2)
		elem = ft_strsplit(av[1], ' ');
	else
	{
		elem = av;
		elem++;
	}
	while (elem[i])
		i++;
	while (i-- > 0)
	{
		num = ft_atoi(elem[i]);
		ft_push(num, *p);
	}
	i = 0;
	if (ac == 2)
	{
		while (elem[i])
			free(elem[i++]);
		free(elem);
	}
}
