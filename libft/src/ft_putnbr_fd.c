/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:55:42 by emsimang          #+#    #+#             */
/*   Updated: 2016/11/24 14:55:45 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int fd, int nbr)
{
	if (nbr < 0)
	{
		ft_putchar_fd(fd, '-');
		ft_putnbr_fd(fd, -nbr);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(fd, nbr / 10);
		ft_putnbr_fd(fd, nbr % 10);
	}
	else
		ft_putchar_fd(fd, nbr + '0');
}
