/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 14:35:51 by emsimang          #+#    #+#             */
/*   Updated: 2016/09/05 11:42:14 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	ft_error_on_repeat(char *str)
{
	int		i;
	int		is_rep;
	int		index;
	char	letter;

	is_rep = 0;
	index = 0;
	while (str[index] != '\0')
	{
		i = 0;
		letter = str[index];
		while (is_rep < 2 && str[i] != '\0')
		{
			if (str[i++] == letter)
				is_rep++;
		}
		index++;
	}
	if (is_rep > 1)
		ft_print_error("Error: repeated values.\n");
}

void	ft_check_repeats(int argc, char **argv)
{
	int		i;
	int		is_rep;
	int		index;
	char	*new;

	is_rep = 0;
	if (argc == 2)
		ft_error_on_repeat(argv[1]);
	else
	{
		index = 1;
		while (index < (argc - 1))
		{
			i = 1;
			new = argv[index++];
			while (is_rep < 1 && i < argc)
			{
				if (!(strcmp(argv[i++], new)))
					is_rep++;
			}
		}
		if (is_rep > 1)
			ft_print_error("Error: repeated values.\n");
	}
}

void	ft_error_check(int argc, char **argv)
{
	int index;

	if (argc == 2)
		ft_validate_args(argv[1]);
	else
	{
		index = 1;
		while (index < argc)
			ft_validate_args(argv[index++]);
	}
}

void	ft_check_args(int argc, char **argv)
{
	if (argc < 2)
		ft_print_error("Error: program missing arguments.\n");
	else
		ft_error_check(argc, argv);
}
