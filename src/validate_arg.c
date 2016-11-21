/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/03 12:20:44 by emsimang          #+#    #+#             */
/*   Updated: 2016/09/05 13:39:20 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_validate_args(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		if (!(str[index] >= 48 && str[index] <= 57) && str[index] != 32)
			ft_print_error("Error: invalid args.\n");
		index++;
	}
	ft_error_repeat(str);
}

void	ft_error_repeat(char *str)
{
	int		i;
	int		index;
	char	let;

	index = 0;
	while (str[index] != '\0')
	{
		i = index + 1;
		let = str[index];
		while (str[i] != '\0')
		{
			if (str[i] == let && let != 32)
			{
				ft_print_error("Error: repeating args.\n");
				break ;
			}
			i++;
		}
		index++;
	}
}
