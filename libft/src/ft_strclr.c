/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 10:16:25 by emsimang          #+#    #+#             */
/*   Updated: 2016/05/14 10:27:00 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_strclr(char *str)
{
	int index;

	index = 0;
	if (str[0] == '\0' || str == NULL)
		;
	else
	{
		while (str[index] != '\0')
		{
			str[index] = '\0';
			index++;
		}
	}
}
