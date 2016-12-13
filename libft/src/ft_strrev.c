/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsimang <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 13:12:26 by emsimang          #+#    #+#             */
/*   Updated: 2016/12/13 13:46:18 by emsimang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	k = ft_strlen(str) - 1;
	tmp = (char*)malloc(sizeof(char) * ft_strlen(str));
	while (i < ft_strlen(str))
	{
		tmp[i] = str[k];
		k--;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
