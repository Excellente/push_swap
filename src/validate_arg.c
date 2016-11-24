/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:20:44 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 16:05:13 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

void	ft_validate_args(char *str)
{
	int		index;
	char	**elems;

	index = 0;
	elems = ft_strsplit(str, ' ');
	while (str[index] != '\0')
	{
		if (!(str[index] >= 48 && str[index] <= 57) && str[index] != 32)
			ft_print_error("Error: invalid args.\n");
		index++;
	}
	ft_error_repeat(elems);
	index = 0;
	while (elems[index])
		free(elems[index++]);
	free(elems);
}

void	ft_error_repeat(char **str)
{
	int		i;
	int		index;
	char	*word;

	index = 0;
	while (str[index] != '\0')
	{
		i = index + 1;
		word = str[index];
		if (ft_atoi(word) > INT_MAX || ft_strlen(word) > 10)
			ft_print_error("ERROR! > maximum int\n");
		while (str[i] != '\0')
		{
			if (ft_strcmp(str[i], word) == 0)
			{
				ft_print_error("Error: repeating args.\n");
				break ;
			}
			i++;
		}
		index++;
	}
}
