/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:38:05 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 16:15:59 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_call_function(char **ops, t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (ft_strslen(ops) > 0)
	{
		while (ops[i])
		{
			if (ops[i][0] == 'p')
				ft_push_in(ops[i], "checker", a, b);
			else if (ops[i][0] == 'r')
				ft_rot_stack(ops[i], "checker", a, b);
			else if (ops[i][0] == 's')
				ft_swap_in(ops[i], "ckecker", a, b);
			else
				ft_print_error("ERROR here\n");
			i++;
		}
	}
}

void	ft_free(char **e, t_stack *p)
{
	int	i;

	i = 0;
	free(p->elements);
	free(p);
	while (e[i])
		free(e[i++]);
	free(e);
}

int main(int ac, char **av)
{
	int		size;
	char	**ops;
	char	**elem;
	char	*line;
	t_stack	*q;
	t_stack	*p;

	if (ac == 2)
	{
		ft_validate_args(av[1]);
		while (get_next_line(0, &line) > 0);
		ops = ft_strsplit(line, '\n');
		elem = ft_strsplit(av[1], ' ');
		size = ft_strslen(elem);
		p = ft_new_stack(size);
		q = ft_new_stack(size);
		ft_init_stack(&p, av[1]);
		ft_call_function(ops, p, q);
		if (ft_issorted(p))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		//printf("%s\n", line);
		//ft_print_stack(p, "p");
		ft_free(ops, q);
		ft_free(elem, p);
	}
	return (0);
}
