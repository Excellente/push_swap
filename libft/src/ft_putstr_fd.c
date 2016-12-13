/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:51:37 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 13:51:39 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(int fd, char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar_fd(fd, str[index]);
		index++;
	}
}
