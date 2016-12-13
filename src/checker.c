/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 15:38:05 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 13:34:33 by emsimang         ###   ########.fr       */
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
				ft_print_error("OPS ERROR\n");
			i++;
		}
	}
}

void	ft_c_free(char **e, t_stack *p)
{
	int	i;

	i = 0;
	free(p->elements);
	free(p);
	while (e[i])
		free(e[i++]);
	free(e);
}

void	ft_init(int ac, char **av, t_check *c)
{
	ft_validate_args(ac, av);
	while (get_next_line(0, &c->line) == 1)
		;
	c->ops = ft_strsplit(c->line, '\n');
	if (ac == 2)
		c->elem = ft_strsplit(av[1], ' ');
	else
		c->elem = av;
}

int		main(int ac, char **av)
{
	int		size;
	t_check c;
	t_stack	*q;
	t_stack	*p;

	if (ac >= 2)
	{
		ft_init(ac, av, &c);
		size = ft_strslen(c.elem);
		p = ft_new_stack(size);
		q = ft_new_stack(size);
		ft_init_stack(&p, ac, av);
		ft_call_function(c.ops, p, q);
		if (ft_issorted(p))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		ft_c_free(c.ops, q);
		if (ac == 2)
			ft_c_free(c.elem, p);
	}
	return (0);
}
